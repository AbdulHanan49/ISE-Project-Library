# Library Management System

Welcome to the **Library Management System**! This is a console-based application designed to manage various functions of a library, allowing librarians to oversee book operations and users to borrow and return books. The system is straightforward and user-friendly, offering easy navigation for both roles.

This project was developed as part of the **Introduction to Software Engineering** course.

---

## Table of Contents

- [Overview](#overview)
- [Features](#features)
  - [Librarian Panel](#librarian-panel)
  - [User Panel](#user-panel)
- [Technologies Used](#technologies-used)
- [Data Management](#data-management)
  - [Book Information](#book-information)
  - [User Information](#user-information)
- [How to Use](#how-to-use)
- [How It Works](#how-it-works)
- [Files Involved](#files-involved)
- [How to Run](#how-to-run)
- [Contributing](#contributing)

---

## Overview

The **Library Management System** serves two main types of users: **librarians** and **regular users**.

- **Librarians**: They can manage books (add, remove, update), track issued books, and handle returns.
- **Users**: They can sign up, log in, search for books, and borrow or return books.

The system uses simple text-based interfaces and file handling to store and retrieve data about books and users.

---

## Features

### Librarian Panel

- **Login**: Librarians can securely log in to access the admin features.
- **Manage Books**:
  - Add, remove, and edit books.
  - View book details like name, author, availability, etc.
- **Book Issue and Return Management**:
  - Issue books to users and track the books issued.
  - Record the return of books.
- **Book Records**: Maintain a record of all issued books and their current status.

### User Panel

- **Sign Up and Login**: Users can create a new account and log in.
- **Search and View Books**: Users can search for books by ID and view their availability.
- **Issue Books**: Request a book to borrow if available.
- **Return Books**: Return borrowed books back to the library.

---

## Technologies Used

- **C++**: The primary language used for the system's implementation.
- **File Handling**: Manages saving and reading data for books and users.
- **Standard Library**: Used for basic operations such as file I/O and console interaction.

---

## Data Management

The system saves all data in **text files** to persist information between sessions.

### Book Information

Each book has the following attributes:
- Unique ID
- Name
- Type (Fiction, Non-Fiction, etc.)
- Author
- Availability (Issued or Available)

### User Information

Each user has:
- Username
- Password
- List of borrowed books

---

## How to Use

1. **Librarian Operations**:
   - Log in to the system.
   - Perform operations like adding, removing, and editing books.
   - Issue and track returns for books.
   
2. **User Operations**:
   - Sign up or log in.
   - Search for books and issue them if available.
   - Return borrowed books.

---

## How It Works

1. **Load Data**: The system loads the list of books and users from text files when the application starts.
2. **Perform Operations**: Depending on whether the user is a librarian or a regular user, the system will display different options for interaction.

---

## Files Involved

Here are the key files involved in the system:

- **Books.txt**: Stores the details of books in the library, such as ID, name, author, type, and availability status.
- **Users.txt**: Stores user information like usernames, passwords, and issued books.

---

## How to Run

### Prerequisites

- Install a C++ compiler (e.g., g++).
- Ensure a terminal or console is available.

### Steps

1. Clone this repository:

   ```bash
   git clone https://github.com/AbdulHanan49/Library-Management-System.git
   cd Library-Management-System
   ```

   Compile the code:

  ```bash
  g++ -o library_management game.cpp
   ```
  Run the game:

    ./library_management

## Contributing

### Contributions are welcome! 

Please follow these steps:

Fork the repository and Create a new branch:
    
    git checkout -b feature-name

Commit your changes:
```bash
  git commit -m 'Add new feature'
```

Push to the branch:

    git push origin feature-name

    Create a pull request.
