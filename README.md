# FileSystemWatcher

## HOW TO RUN

Just open project in QtCreator and hit build&run

## Comments
Supported platforms: Linux only
(can be extended after fixing WatchedPath class)


Key points:
* OK - use of QFileSystemWatcher class
* OK - support of watching multiple directories
* OK - added directories are scanned recursively
* OK - when new sub-directory added it is added to watched directories
* OK - adding directories available only through UI
* OK - app recognizes 4 event types (Created, Deleted, Edited, Renamed), saves path, timestamp and fact if it was a folder or a file
* OK - logs about event are independently printed to console output
* NOK - no image downloading when Delete event occurs (I guess QNetworkAccessManager + QThread (QThreadPool) should be used)

Additional:
* OK - UI implemented using Qml
* OK - data stored using Qt models
* OK - using latest version of Qt

General comments:
* WatchedPathsList don't show every recursively found directoriesi (only user selected dirs are shown), but EventTable will show events linked with recursively found dirs/files.
* Somewhere in evaluateEvent() function there is still a bug that causes to return wrong event sometimes.
* EventView is not resizing (some magic numbers in QML code).
* EventView should have proper header (for example with HorizontalHeaderView)
* EventView is not following events (or coming back after clearing events).
* When app starts watching -> not relevant buttons could be disabled (so user can see that app is working).
* Created Theme.qml to handle number shared between QML files.
