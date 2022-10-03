//C# program to get all stack frames using StackTrace class

using System;
using System.Diagnostics;

class Demo
{
    public static void Main()
    {
        StackTrace trace = new StackTrace();
        StackFrame[] frames;
        
        frames= trace.GetFrames();
        
      
        Console.WriteLine("Frames: ");
        foreach (StackFrame frame in frames)
        {
            Console.WriteLine("\tMethod Name: "+frame.GetMethod().Name);
            Console.WriteLine("\tModule Name: "+frame.GetMethod().Module+"\n");
        }
    }
}
