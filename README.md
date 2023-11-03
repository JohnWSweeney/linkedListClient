# linkedListClient

Companion client app for [linkedListServer](https://github.com/JohnWSweeney/linkedListServer).

## ChangeLog
v0.0.10
- Added "dlist" to demoTypes string vector in commands to control doubly linked list demo running on server.

v0.0.9
- Removed output field from command struct.
- Updated convertCmdToString in client cpp to add all command struct fields to JSON string.

v0.0.8
- Updated cmd struct and commands cpp to control singly linked list demo running on server.

v0.0.7
- Added convertCmdToString to client to streamline command struct conversion to string, in JSON format.
- Updated startMenu, populateCmd, and client stateMachine funciton to end session from client.

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