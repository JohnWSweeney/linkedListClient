# linkedListClient

Companion client app for [linkedListServer](https://github.com/JohnWSweeney/linkedListServer).

## ChangeLog
0.0.16
- Updated commands cpp to enable control of priorityQueue demo running on server.
	- Added "priorityQueue" to demoTypes string vector.
	- Added priorityQueue function string vectors.
	- Added "priorityQueue" condition to populateFunctionLists.

- 0.0.15
- Updated commands cpp to enable control of deque demo running on server.
	- Added "deque" to demoTypes string vector.
	- Added deque function string vectors.
	- Added "deque" condition to populateFunctionLists.

v0.0.14
- Updated commands cpp to enable control of queue demo running on server.
	- Added "queue" to demoTypes string vector.
	- Added queue function string vectors.
	- Added "queue" condition to populateFunctionLists.
- Updated populateCmd in commands cpp to allow only one demo running on the server at a time.

v0.0.13
- Updated commands cpp to enable control of stack demo running on server.
	- Added "stack" to demoTypes string vector.
	- Added stack function string vectors.
	- Added "stack" condition to populateFunctionLists.

v0.0.12
- Added "cdlist" to demoTypes string vector in commands cpp to control circular doubly linked list demo running on server.

v0.0.11
- Added "cslist" to demoTypes string vector in commands cpp to control circular singly linked list demo running on server.

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