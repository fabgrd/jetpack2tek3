
# JetPack2Tek3

The goal of this project is to create a game like [Jetpack Joyride](https://en.wikipedia.org/wiki/Jetpack_Joyride) in C with a game server and a client program.



## How to play
Compile with Makefile
```bash
make

./serverJ2T3 -g [gravity] -m [map] -p [port]
```
 😏 *Here's a recommanded map & gravity*
 ```bash
 ./serverJ2T3 -g 5 -m server/map2 -p [port]
  ```
Open a new terminal for player 1...
```bash
./clientJ2T3 -h [host] -p [port]
 ```
 And in another one for player 2 !
 ```bash
./clientJ2T3 -h [host] -p [port]
 ```

🕹 **Enjoy !**

⚠ *Epitech students, this repo is here to inspire, not to copy. I won't be responsible if you get a -42* ⚠
