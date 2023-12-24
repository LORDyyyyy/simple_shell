# Simple Shell Project
This project implements a simple UNIX command interpreter shell in C programming language, capable of running commands in both interactive and non-interactive modes. It provides a basic understanding of how shells work and serves as a starting point for further exploration and customization.


## Main Features
- Runs in both interactive (REPL) and non-interactive modes
- Implements built-in `exit` and `env` commands
- Splits input into tokens using a delimiter
- Forks processes to execute commands from `$PATH`
- Searches across list of paths to locate commands
- Outputs error if command not found
- Counts number of commands executed


## Function Definitions
### Main Shell Functions
**shell**
- Decides whether to run in interactive or non-interactive mode

**shell_interactive** 
- Implements REPL loop prompting for user input  

**shell_noninteractive**
- Reads input from stdin and executes

### Execute Command Functions
**handle_execution**
- Parses input and executes commands  

**execute_fork**
- Spawns process and runs command using execve


## Future Enhancements

**Input/Output**

- Implement output redirection (> and >>)
- Implement input redirection (< and <<) 
- Implement pipes (|) to connect commands

**Additional Builtins** 

- Add more built-in commands like echo, help etc.

**User Customization**

- Set up initialization script to run on shell start
- Add command history and search
- Support tab autocompletion 

**Error Handling**

- Improve control-C signal handling
- Enhance error messages and logging

**Batch/Scripting** 

- Support running script files with multiple commands
- Handle line continuation with backslash
- Add conditional logic and loops


## Getting Started  <!-- Instructions for setting up and running the project -->

### Prerequisites  <!-- Software requirements for running the project -->

Ensure you have the following installed:

- C Compiler (e.g., GCC)
- Standard C Library Headers

### Installation  <!-- Steps to clone and compile the project -->

Clone the repository and compile the source code:

```bash
git clone https://github.com/mohamedtharwat000/simple_shell.git
cd simple_shell
gcc -o your_shell_name *.c
```

## Usage  <!-- Instructions for using the project -->

### Interactive Mode  <!-- How to use the shell interactively -->
Run the shell:

```bash
./your_shell
Enter commands interactively.
```

### Non-Interactive Mode  <!-- How to use the shell in non-interactive mode -->
Run the shell with a script:

```bash
./your_shell < script.txt
Provide a script with commands to execute non-interactively.
```

## Contributing

Contributions are welcome! Here are some ways you can contribute to this project:

- Report bugs and issues
- Fix bugs and issues
- Add new validation functionality
- Improve styling and overall UX
- Refactor code to improve quality
- Write documentation and improve existing docs

To contribute:
1. Fork the repository
2. Create a new branch
3. Make your changes and commit them
4. Push your branch and submit a pull request

I will review pull requests and provide feedback.

## License

This project is open source and available under the [MIT License](LICENSE).

## Credits

Created by Mohammed Khalid and Mostafa Mokhtar
