// A Java program for a Server
import java.net.*; // it import's the input and output function's,
import java.io.*;  //adding a Library/Package full of classes and methods that are premade for ease of use
public class Server
{
	//initialize socket and input stream
	private Socket socket = null;					// implements one side of a two-way connection between your Java program and another program on the network. 
	private ServerSocket server = null;   //ServerSocket is a java.net class that provides a system-independent implementation of the server side of a client/server socket connection. 
	private DataInputStream in = null;   //A data input stream lets an application read primitive Java data types from an underlying input stream in a machine-independent way. 

	// constructor with port
	public Server(int port)
	{
		// starts server and waits for a connection
		try
		{
			server = new ServerSocket(port);			//creates a Java object and allocates memory for it on the heap. 
			System.out.println("Server started");

			System.out.println("Waiting for a client ...");

			socket = server.accept();
			System.out.println("Client accepted");

			// takes input from the client socket
			in = new DataInputStream(
				new BufferedInputStream(socket.getInputStream()));

			String line = "";

			// reads message from client until "Over" is sent
			while (!line.equals("Over"))
			{
				try										//Java try block is used to enclose the code that might throw an exception. It must be used within the method. 
				{
					line = in.readUTF();
					System.out.println(line);

				}
				catch(IOException i)			//Java catch block is used to handle the Exception by declaring the type of exception within the parameter.
				{
					System.out.println(i);
				}
			}
			System.out.println("Closing connection");

			// close connection
			socket.close();
			in.close();
		}
		catch(IOException i)
		{
			System.out.println(i);
		}
	}

	public static void main(String args[])
	{
		Server server = new Server(5000);
	}
}

