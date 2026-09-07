# Simple Line Editor in C

## Portfolio Building — Studio Course
### 3rd Semester Coding Competition

A simple command-line line editor developed in C. The editor allows users to create, view, modify, search, and save a small text document directly from the terminal.

---

## Team Member

| Name | SRN |
|---|---|
| ABHISHEK MAURYA | R25EJ004 |

---

## Features Implemented

### Core Features

1. **Insert a Line**
   - Adds a new line at a specified line number.
   - Existing lines are shifted down automatically.

2. **Delete a Line**
   - Deletes a selected line using its line number.
   - Remaining lines are shifted up.

3. **Display Document**
   - Displays all current lines.
   - Each line is shown together with its line number.

4. **Edit a Line**
   - Allows the user to modify an existing line.

5. **Save File**
   - Saves the current document to a `.txt` file.

6. **Load File**
   - Loads an existing `.txt` file into the editor.

### Bonus Features

7. **Search**
   - Searches for a word or phrase.
   - Displays the line number where the text is found.

8. **Find & Replace**
   - Searches for a word or phrase and replaces it throughout the document.

9. **Line / Word / Character Count**
   - Displays basic document statistics.

---

## Data Structure

The editor uses a **2D character array** to store the document.

```c
char lines[MAX_LINES][MAX_LENGTH];
```

- `MAX_LINES` defines the maximum number of lines.
- `MAX_LENGTH` defines the maximum number of characters per line.
- Each row of the array represents one line of the document.

This structure was chosen because it is simple to implement, easy to understand, and suitable for a small command-line editor.

---

## Available Commands

| Command | Description |
|---|---|
| `insert` | Insert a new line |
| `delete` | Delete a line |
| `edit` | Edit an existing line |
| `display` | Display the document |
| `save` | Save document to a text file |
| `load` | Load document from a text file |
| `search` | Search for a word or phrase |
| `replace` | Find and replace text |
| `stats` | Display document statistics |
| `help` | Display available commands |
| `quit` | Exit the editor |

---

## How to Compile

Make sure **GCC** is installed on your system.

Open the terminal in the project directory and run:

```bash
gcc main.c -o editor
```

If there are no compilation errors, the executable will be created.

---

## How to Run

### Windows

```bash
editor.exe
```

### Linux / macOS

```bash
./editor
```

---

## Example Usage

Start the editor:

```text
====================================
       SIMPLE LINE EDITOR
====================================

Type 'help' to see available commands.

> insert
Enter line number to insert at (1-1): 1
Enter text: Hello World
Line inserted successfully.

> insert
Enter line number to insert at (1-2): 2
Enter text: This is a line editor.
Line inserted successfully.

> display

----- DOCUMENT -----
1: Hello World
2: This is a line editor.
--------------------

> search
Enter word or phrase to search: World
Found on line 1: Hello World

> stats

----- STATISTICS -----
Lines      : 2
Words      : 6
Characters : 34
----------------------

> save
Enter filename: document.txt
File saved successfully.

> quit
Exiting editor...
```

---

## Project Structure

```text
Simple-Line-Editor/
│
├── main.c
├── README.md
└── help.txt
```

---

## Requirements

- C Compiler (GCC recommended)
- Command-line terminal
- Windows, Linux, or macOS

---

## Competition Requirements Covered

The project implements the required line-editor functionality including **insert, delete, and display**, along with additional features such as file saving/loading, search, find & replace, and document statistics. The competition specifically requires at least 2–3 core features and provides bonus credit for additional features. 
---

## Author

**ABHISHEK MAURYA**  
**SRN: R25EJ004**

Portfolio Building — Studio Course  
3rd Semester Coding Competition