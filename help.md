SIMPLE LINE EDITOR - HELP FILE
==============================

Author:
ABHISHEK MAURYA
SRN: R25EJ004


1. ABOUT THE PROGRAM
--------------------

This program is a simple command-line line editor written in C.

It allows the user to create and modify a small text document one
line at a time. Each line is identified by its line number.

The editor supports inserting, deleting, editing, displaying,
saving, loading, searching, replacing text, and viewing document
statistics.


2. AVAILABLE COMMANDS
---------------------

insert
    Insert a new line into the document.

    Usage:
        insert

    The program asks for the line number and the text to insert.

    Example:
        editor> insert
        Enter line number: 1
        Enter text: Hello World


delete
    Delete a line from the document.

    Usage:
        delete

    Example:
        editor> delete
        Enter line number: 1


edit
    Modify an existing line.

    Usage:
        edit

    Example:
        editor> edit
        Enter line number: 1
        Enter new text: Hello C Programming


display
    Display all lines currently stored in the document.

    Usage:
        display

    Example output:
        1: Hello World
        2: This is a line editor.


save
    Save the current document to a text file.

    Usage:
        save

    The program asks for the file name.

    Example:
        editor> save
        Enter filename: document.txt


load
    Load a previously saved text file.

    Usage:
        load

    Example:
        editor> load
        Enter filename: document.txt


search
    Search for a word or text in the document.

    Usage:
        search

    The program asks for the text to search.

    Example:
        editor> search
        Enter text to search: C


replace
    Find a piece of text and replace it with another text.

    Usage:
        replace

    Example:
        editor> replace
        Enter text to find: Hello
        Enter replacement text: Hi


stats
    Display document statistics.

    The statistics include:
        - Number of lines
        - Number of words
        - Number of characters

    Example:
        editor> stats


help
    Display the available commands.

    Usage:
        help


quit
    Exit the line editor.

    Usage:
        quit


3. TYPICAL WORKFLOW
-------------------

A typical session can be performed as follows:

1. Start the editor.
2. Use "insert" to add lines.
3. Use "display" to view the document.
4. Use "edit" to modify a line.
5. Use "delete" to remove a line.
6. Use "search" to find text.
7. Use "replace" to replace text.
8. Use "stats" to view document statistics.
9. Use "save" to save the document.
10. Use "quit" to exit.


4. DATA STORAGE
---------------

The editor stores the document using a two-dimensional character
array.

Each row of the array represents one line of the document.

The program uses fixed limits for:
    Maximum number of lines: 1000
    Maximum characters per line: 500


5. FILE HANDLING
----------------

The "save" command writes the current document to a text file.

The "load" command reads a previously saved text file and loads its
contents into the editor.

This allows the user to continue working on a document after
restarting the program.


6. INPUT VALIDATION
-------------------

The program checks for invalid input such as:

    - Invalid line numbers
    - Empty or invalid document positions
    - Exceeding the maximum number of lines
    - Lines exceeding the maximum supported length
    - Attempting to delete or edit a non-existing line
    - File opening errors


7. COMMAND SUMMARY
------------------

    insert    - Insert a new line
    delete    - Delete a line
    edit      - Edit an existing line
    display   - Display the complete document
    save      - Save document to a file
    load      - Load document from a file
    search    - Search for text
    replace   - Find and replace text
    stats     - Show line, word and character counts
    help      - Show help information
    quit      - Exit the program


8. COMPILATION
--------------

Using GCC:

    gcc main.c -o editor

On Windows, run:

    editor.exe

On Linux/macOS, run:

    ./editor


9. IMPORTANT NOTES
------------------

- Line numbers start from 1.
- Lines are stored in memory while the editor is running.
- Use the "save" command to permanently store the document.
- Use the "load" command to open an existing text file.
- The editor is terminal-based and does not require a graphical
  interface.


10. AUTHOR
----------

ABHISHEK MAURYA
SRN: R25EJ004

Simple Line Editor in C
3rd Semester Coding Competition