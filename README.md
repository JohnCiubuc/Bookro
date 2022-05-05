# Bookro

Open source project to combine Vim's quickmark / bookmark system with macros (bookmark + macro = bookro).

Ideal functionality is for a user to press a key string that indicates a mark, such as `'A`. This will prompt the user if they want to save a macro to that keystroke. If a macro is saved, it'll auto-run that macro.

Macros will be transient, much like the quickmark system. The idea is to simplify workflow when working on a current document, like an email, rather than being permanent. However, will probably write a feature for permanent marks too if it becomes prudent.

Might run into an issue where writing a mark will be commonplace in writing, and keeps prompting the system, but time will tell


Submodule broken atm, will fix later. But it's the wayland-autotype branch that's needed
