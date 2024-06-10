# Overview

{This C# program establishes a server-client architecture using TCP/IP sockets for communication. The server continuously listens for incoming client connections and relays any messages received from clients to all connected clients. Meanwhile, clients can send messages to the server, which are then disseminated to all other connected clients.}

{This program demonstrates basic socket programming in C# for establishing communication between a server and multiple clients.}


[Software Demo Video](still uploading to youtube will post in comments when its uploaded)

# Development Environment
Programming Language: C#

C# is a versatile, object-oriented programming language developed by Microsoft. It's commonly used for developing various types of applications, including desktop, web, and mobile applications.
.NET Framework:

The code is developed using the .NET Framework, which is a software development framework developed by Microsoft. It provides a large class library and supports multiple programming languages, including C#. The .NET Framework facilitates building and running software applications for Windows.
Visual Studio:

Visual Studio is an integrated development environment (IDE) provided by Microsoft for developing software applications. It offers a range of tools and features for coding, debugging, and deploying applications. In this case, Visual Studio would be used for writing, compiling, and debugging the C# code.
System.Net.Sockets Namespace:

The code utilizes classes from the System.Net.Sockets namespace, which is part of the .NET Framework. This namespace provides classes for implementing network communication using sockets. Sockets are fundamental for establishing connections between client and server applications over a network.
Threading:

The System.Threading namespace is used to implement multi-threading in the application. Threads are used to handle multiple client connections simultaneously without blocking the main execution thread.
Encoding Class:

The Encoding class, also part of the .NET Framework, is used to convert strings to byte arrays and vice versa. It facilitates encoding and decoding of text-based data for communication over the network.
# Useful Websites

- [Microsoft](https://learn.microsoft.com/en-us/dotnet/)
- [W3 Schools](https://www.w3schools.com/cs/index.php)

# Future Work

- Implement a robust user authentication system to verify the identity of users before allowing them to join the chat. This could involve integrating with OAuth providers like Google or Facebook for single sign-on, or implementing your own authentication mechanism with username/password credentials. Additionally, implement authorization mechanisms to control access to specific chat rooms or features based on user roles or permissions.

- Enhance the security of the chat application by implementing end-to-end encryption for messages exchanged between clients and the server. This would ensure that messages are encrypted before leaving the sender's device and decrypted only upon reaching the intended recipient, thereby protecting the confidentiality of the communication. You could use cryptographic libraries like Bouncy Castle or .NET's built-in cryptography APIs to implement encryption algorithms such as AES or RSA.

- Enable users to share a variety of media types, including images, videos, documents, and more, directly within the chat interface. Implement functionality to upload and download files securely, with support for file previews and thumbnails. You could integrate with cloud storage services like AWS S3 or Azure Blob Storage to store and retrieve files, or implement peer-to-peer file transfer protocols for direct file exchange between clients