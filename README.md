## TEXT ADVENTURE GAME
Welcome to my **Zork like Text Adventure Game**, a small console-based story in which you explore a world, collect items, and find a way to win.
This game was created as a C++ programming assignment by **Meritxell Algueró Manrique** in 2025.
Link to my Zork like game repository: https://github.com/MeriAlguero/Zork.git

---
## HOW TO RUN
1. Clone or download the project from this repository: https://github.com/MeriAlguero/Zork.git
2. Open the project in **Visual Studio 2019 or later**.
3. Build and run the project (`Ctrl + F5` or use the green Run button).
4. The game will launch in a console window.

---
## HOW TO PLAY
- Use simple **text commands** to explore rooms, collect items, and interact with the enviroment.
- Move through the world by typng: 'go north', 'go south', 'go east', 'go west', and its variables.
- You can pick up, drop and check items from your **inventory**, as well as store items in your **bag**.
- Goal to finish the game: **Find the money** left by your father.

---
## COMMANDS
| Command Example                                               | Description                                     |
|---------------------------------------------------------------|-------------------------------------------------|
| `go [direction]`  /  `walk [direction]` / `move [direction]`  | Move in a direction [south, north, east, west]  |
|`look around`                                                  | Shows in the console what you see in the room   |
| `get [item]`/ `take [item]`                                   | Pick up an item from the room                   |
| `examine [item]`/ `inspect [item]`                            | Check an item of your selection once picked     |
| `drop [item]`                                                 | Drop an item from your inventory                |
| `inventory`                                                   | Show all items you're carrying or have in your bag  |
| `put [item] in bag`                                           | Store an item in your bag                       |
| `grab [item] from bag`                                        | Retrieve an item from your bag                  |
| `bag` / `Bag` / `open bag` / `check bag`                      | Show all items stored in your bag               |
| `dictionary` / `help`                                         | Show the command list                           |
| `quit` / `exit`                                               | Exit the game                                   |
---
## HOW TO FINISH THE GAME
1. Explore the rooms to find useful items (key, book, bandages, etc.)
2. Use the **key** to unlock the tresure room / **secret room**.
3. In the secret room, take the *money*.
4. Once you have the money, the game will end with a victory message.

---
## STRUGGLES
I'm more well versed in C#, so most of the time I tend to think first how I would do it in that lenguage. Due to that, sometimes I had to search the 'convertion' from one lenguage to another, however, because they share some similarities I was able to keep going.
I made a simpler game because of this issue, but that doesn't mean that upon having more time I wouldn`t implement more features. I wanted it to be functional even if that meant not having as many features as I wished. 

---
## AUTHOR
**Meritxell Algueró Manrique**  
_Created in 2025 as part of a programming assignment using C++ and object-oriented principles._

---
## LICENSE
MIT License

Copyright (c) [2025] [Meritxell Algueró Manrique]

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
