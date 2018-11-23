## Deprecation Notice
Please use the 'New Torrent' feature in your torrent client instead. This
project was created when I thought this feature didn't work; but it does.

# börk
A torrent generator, written in C++. Named after a common theme in
[r/polandball comics](https://www.reddit.com/r/polandball) and after what it was
originally going to be a fork of; [`quark`](https://tools.suckless.org/quark).

## Dependencies
Börk depends on [libtorrent](https://libtorrent.org), often known as
`libtorrent-rasterbar`.

## Usage
Run `make` and then `bork`. It takes two command line arguments: `file` and
`tracker`. Enter the file you want to use in `file` and a tracker in `tracker`.
[Don't know what to pick? Try one from here.](https://raw.githubusercontent.com/ngosang/trackerslist/master/trackers_best.txt).

## License
Börk (styled 'bork' in environments where diacritics are prohibited) is licensed
under the GNU General Public License version 3. See the [LICENSE](LICENSE) file.
