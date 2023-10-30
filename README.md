# linkedListClient

Companion client app for [linkedListServer](https://github.com/JohnWSweeney/linkedListServer).

## ChangeLog
v0.0.6
- Added "stop" and "exit" conditions to startMenu function in start cpp.

v0.0.5
- Updated commands, client, startMenu to distinguish user commands to start client thread and update cmd parameters for JSON messages.

v0.0.4
- Updated client, threads headers/cpps to accept user server IP and port number commands.

v0.0.3
- Added commands header/cpp and updated startMenu to accept user commands to connect to server.

v0.0.2
- Renamed Client::run to "connectToServer", Client::message to "stateMachine".
- Move connect to server function from Client::stateMachine to Client::connectToServer.

v0.0.1
- Added basic json transmit functionality to client cpp.

v0.0.0
- Initial commit.
	- Basic client functionality.