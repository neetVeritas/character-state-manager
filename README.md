# Oro / ***Character State Manager***

This tool is an extension of Oro. It allows the manipulation of character state for RumbleFighter, an action fighting MMO. It was written in C++ using C++ 11 conventions and the win32 api.

To use this tool, inject it into your RumbleFighter client ( preferably using manual map ). Once in-game:

* F1: State reset
* F2: Access basic commands
* F3: Access elevated room master state

The concept is simple, but this character state manager allows players to access otherwise inavailable commands. Because the game cannot properly process the player's state, users can use CA(community advisor)/GM(game master) esque commands. The full extent of the commands that can be used is unclear, but the following commands have been found and confirmed to work:

* /Close [username] ; Will DC the user
* /Location [user] ; Will return the room ID of the user
* /RoomNotify [room_id] [message] ; Will create a room announcement
* /RemoveRoom [room_id] ; Will close an entire room
* /kick [username] ; Will kick any user from any room regardless of whether your room master or not
* /RoomInfo [room_id/NULL] ; will show users in a room or all rooms with all users
* /Move [username] ; Move to the room a user is in regardless of whether it is password protected

The following commands are available, but the state at which that can be used is uncertain:

* Mute ; ???
* Ban ; ???
* User ; ???

All commands can be made available by modifying the following addresses in static memory:

```
42575F: jne 426225 ; 0F 85
425A4D: jne 425CE9 ; 0F 85
```

Using our memory api:

```c++
memapi::write_memory(0x42575F, "0F 85");
memapi::write_memory(0x425CE9, "0F 85");
```

Guild commands can also be accessed by modifying guild state:

```c++
memapi::pointer::write_int(char_base, 0xD13C, 0); // # enable
memapi::pointer::write_int(char_base, 0xD13C, 2); // # disable
```

* //s c/#hagnedGMark ?
* //s c/#losed [username] [guild*optional*]
* //s a/#ccept [username] [guild*optional*]
* //s changeID ?

It's my hypothesis there are more commands at your disposal, it's just a matter of flipping switches. It seems a lot of these commands are also actually called by the client itself under the hood during certain state changes or events.
