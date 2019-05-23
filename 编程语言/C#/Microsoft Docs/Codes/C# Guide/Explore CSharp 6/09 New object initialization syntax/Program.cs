using System;
using System.Collections;
using System.Collections.Generic;

namespace _09_New_object_initialization_syntax
{
    public class Point3D : IEnumerable
    {
        // Properties
        // public double X { get; set; }
        // public double Y { get; set; }
        // public double Z { get; set; }
        private double[] Point { get; }

        // Constructor
        public Point3D(double x, double y, double z)
        {
            // X = x;
            // Y = y;
            // Z = z;
            Point = new double[3];
            Point[0] = x;
            Point[1] = y;
            Point[2] = z;
        }

        public IEnumerator GetEnumerator() => $"x:{X}, y{this.Y}, z{this.Z}";

    }

    // When you implement IEnumerable, you must also implement IEnumerator.
    public class PeopleEnum : IEnumerator
    {
        public object Current => throw new NotImplementedException();

        public bool MoveNext()
        {
            throw new NotImplementedException();
        }

        public void Reset()
        {
            throw new NotImplementedException();
        }
    }

    public class Path : IEnumerable<Point3D>
    {
        private List<Point3D> points = new List<Point3D>();
        public IEnumerator<Point3D> GetEnumerator() => points.GetEnumerator();
        IEnumerator IEnumerable.GetEnumerator() => points.GetEnumerator();

        public void Add(Point3D pt) => points.Add(pt);
    }

    public static class Extensions
    {
        public static void Add(this Path path, double x, double y, double z) => path.Add(new Point3D(x, y, z));
    }

    class Program
    {
        static void Main(string[] args)
        {
            Path path = new Path();
            // Point3D point = new Point3D(1, 2, 3);
            Extensions.Add(path, 1, 2, 3);

            Console.WriteLine($"Output path and point: {path.GetEnumerator()}");
        }
    }
}
