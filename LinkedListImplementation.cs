// C# program to illustrate how
// to create a LinkedList
using System;
using System.Collections.Generic;

class GFG {

	// Main Method
	static public void Main()
	{

		// Creating a linkedlist
		// Using LinkedList class
		LinkedList<String> my_list = new LinkedList<String>();

		// Adding elements in the LinkedList
		// Using AddLast() method
		my_list.AddLast("Zoyat");
		my_list.AddLast("Shalu");
		my_list.AddLast("Rohit");
		my_list.AddLast("Rohi");
		my_list.AddLast("Juhita");
		my_list.AddLast("Utkarsh");

		Console.WriteLine("Best students of XYZ university:");

		// Accessing the elements of
		// LinkedList Using foreach loop
		foreach(string str in my_list)
		{
			Console.WriteLine(str);
		}
	}
}
