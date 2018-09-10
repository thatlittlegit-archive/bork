// bork.cpp: Main source file for Börk.
//
// This code was written by thatlittlegit, and is licensed under the GNU
// General Public License, version 3. It comes with no warranty. What users do
// with this software is not the responsibility of thatlittlegit.

// Thanks to Spyros and user3782779 on StackOverflow:
//    Spyros: fileSize(const char*)                              /a/5840160
//    user3782779: overall structure of libtorrent interaction   /q/28041730

#include <libtorrent/create_torrent.hpp>
#include <libtorrent/file_storage.hpp>
#include <iostream>
#include <fstream>
#include <string.h>

#include "logging.hpp"

#define quit_with_error(error, code) \
	{                                \
		log$error(error);            \
		exit(code);                  \
	}

using namespace libtorrent;

int fileSize(const char *filename)
{
	// thanks to Spyros on StackOverflow (answer 5840160)
	std::ifstream in(filename, std::ifstream::ate | std::ifstream::binary);

	if (in.tellg() == -1)
		quit_with_error("Couldn't get file size of " << filename
													 << "; does it exist?",
						12);
	return in.tellg();
}

int main(int argc, char *argv[])
{
	log$info("börk! version " << VERSION << "; by thatlittlegit");

	// Don't segfault with no arguments
	if (argc < 2)
		quit_with_error("Invalid number of arguments; see " << argv[0]
															<< " --help",
						11);
	if (strcmp(argv[1], "--help") == 0 || strcmp(argv[1], "-h") == 0) {
		std::cout
				<< "Welcome to Börk, a file-sharing program built with libtorrent by thatlittlegit.\n";
		<< "It's licensed under the GNU GPL 3. (thatlittlegit is not responsible for any\n";
		<< "									files transferred that are not legal to\n";
		<< "									transfer, such as 'cracked' games.)\n";
		<< "\n";
		<< "Usage: " << argv[0] << " <file> <tracker>\n";
		<< "	   Creates a new torrent file for <file>, using <tracker> as a tracker.\n";
		<< "	   " << argv[0] << " [--help|-h]\n";
		<< "	   Shows this help text.\n";
		<< "\n";
		<< "Written with C++. Contact thatlittlegit at <personal@thatlittlegit.tk>."
		<< std::endl;
		return 0;
	}

	if (argc != 3)
		quit_with_error("Invalid number of arguments; see " << argv[0]
															<< " --help",
						11);
	log$debug("passed argc checks");

	file_storage files;
	files.add_file(argv[1], fileSize(argv[1]));
	log$debug("created file_storage");

	create_torrent torrent(files);
	torrent.add_tracker(argv[2]);

	char *borkinfo = (char *)malloc(strlen("bork ") + strlen(VERSION));
	strcat(borkinfo, "bork ");
	strcat(borkinfo, VERSION);
	torrent.set_creator(borkinfo);

	char *output_file =
			(char *)malloc(strlen(argv[1]) + 8); // 8 = strlen(".torrent")
	strcat(output_file, argv[1]);
	strcat(output_file, ".torrent");

	set_piece_hashes(torrent, ".");

	std::ofstream out(output_file, std::ios_base::binary);
	bencode(std::ostream_iterator<char>(out), torrent.generate());
}