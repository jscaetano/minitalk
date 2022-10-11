This a project called minitalk for 42 School.
======

The goal is to create a communication program in the form of a client and a server.

The server must be initiated first.
The client takes two args: the process id from the server, and a string to send to the server.
When initiated, the server must print its process id.
Once the string has been received, the server must print it.

The server should be able to receive strings from several clients in a row without
needing to restart.

The communication has to be done only using UNIX signals.
Only this two signals can be used: SIGUSR1 and SIGUSR2.

The bonus part is to make the server acknowledge the message recieved by sending back a signal to the client, and to have unicode character support.

The full subject was added to the root of the repository.
