using System;
using System.Collections.Generic;
using System.Net;
using System.Net.Sockets;
using System.Text;
using System.Threading;

public class Server {
    private TcpListener listener;
    private List<TcpClient> clients = new List<TcpClient>();

    public Server() {
        listener = new TcpListener(IPAddress.Any, 8888);
        listener.Start();
        Console.WriteLine("Server started...");
        AcceptClients();
    }

    private void AcceptClients() {
        while (true) {
            TcpClient client = listener.AcceptTcpClient();
            clients.Add(client);
            Console.WriteLine("Client connected.");

            Thread clientThread = new Thread(HandleClient);
            clientThread.Start(client);
        }
    }

    private void HandleClient(object obj) {
        TcpClient client = (TcpClient)obj;
        NetworkStream stream = client.GetStream();
        byte[] buffer = new byte[1024];

        while (true) {
            int bytesRead = stream.Read(buffer, 0, buffer.Length);
            string dataReceived = Encoding.ASCII.GetString(buffer, 0, bytesRead);
            Console.WriteLine("Received from client: " + dataReceived);

            // Broadcast message to all clients
            BroadcastMessage(dataReceived);
        }
    }

    private void BroadcastMessage(string message) {
        foreach (TcpClient client in clients) {
            NetworkStream stream = client.GetStream();
            byte[] buffer = Encoding.ASCII.GetBytes(message);
            stream.Write(buffer, 0, buffer.Length);
        }
    }
}

public class Client {
    private TcpClient client;

    public Client() {
        client = new TcpClient();
        client.Connect("127.0.0.1", 8888); // Connect to localhost
        Console.WriteLine("Connected to server...");

        Thread receiveThread = new Thread(ReceiveMessages);
        receiveThread.Start();
    }

    private void ReceiveMessages() {
        NetworkStream stream = client.GetStream();
        byte[] buffer = new byte[1024];

        while (true) {
            int bytesRead = stream.Read(buffer, 0, buffer.Length);
            string dataReceived = Encoding.ASCII.GetString(buffer, 0, bytesRead);
            Console.WriteLine("Received from server: " + dataReceived);
        }
    }

    public void SendMessage(string message) {
        NetworkStream stream = client.GetStream();
        byte[] buffer = Encoding.ASCII.GetBytes(message);
        stream.Write(buffer, 0, buffer.Length);
    }
}

class Program {
    static void Main(string[] args) {
        // Start server
        Thread serverThread = new Thread(() => {
            Server server = new Server();
        });
        serverThread.Start();

        // Create and connect clients
        Client client1 = new Client();
        Client client2 = new Client();

        // Send messages
        client1.SendMessage("Hello from client 1");
        client2.SendMessage("Hello from client 2");
    }
}


// Chat gpt was used for this. 