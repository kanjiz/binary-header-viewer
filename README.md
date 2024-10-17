# File Header Viewer

File Header Viewer is a C++ project that allows users to view and analyze the headers of binary files. It provides functionality for reading file headers, displaying them in a user-friendly format, and logging any errors that occur during the process.

## Features

- Read and display file headers
- Support for various file types
- Customizable logging levels
- Error handling and reporting

## Prerequisites

- C++20 compatible compiler (e.g., Clang, GCC)
- CMake (version 3.10 or higher)
- Visual Studio Code (recommended for development)

## Building the Project

This project uses CMake as its build system. To build the project:

1. Clone the repository:

   ```
   git clone https://github.com/yourusername/file-header-viewer.git
   cd file-header-viewer
   ```

2. Create a build directory and run CMake:

   ```
   mkdir build
   cd build
   cmake ..
   ```

3. Build the project:

   ```
   cmake --build .
   ```

## Usage

After building the project, you can run the File Header Viewer as follows:

```
./FileHeaderViewer <file_path> [num_bytes]
```

- `<file_path>`: Path to the file you want to analyze
- `[num_bytes]`: (Optional) Number of bytes to read from the file header (default: 16)

## Development Environment Setup

1. Copy the `.vscode/*.example` files to their corresponding `.vscode/*` files:
   - `.vscode/c_cpp_properties.json.example` → `.vscode/c_cpp_properties.json`
   - `.vscode/tasks.json.example` → `.vscode/tasks.json`

2. Adjust the copied files as needed for your environment:
   - In `tasks.json`: Modify build commands and compiler paths as necessary.
   - In `c_cpp_properties.json`: Set the appropriate compiler path and include directories.

3. Ensure you have the C/C++ and CMake extensions installed in Visual Studio Code.

## Contributing

Contributions are welcome! Please feel free to submit a Pull Request.

## License

This project is licensed under the CC0 1.0 Universal License. See the [LICENSE](LICENSE) file in the project root for the full license text.
