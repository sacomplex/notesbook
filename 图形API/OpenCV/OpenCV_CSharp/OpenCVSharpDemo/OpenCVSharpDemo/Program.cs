using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using OpenCvSharp;

namespace OpenCVSharpDemo
{
    class Program
    {

        static void Main(string[] args)
        {
            Mat source = new Mat(@"01.jpg", ImreadModes.Color);
            Cv2.ImShow("Demo", source);
            Cv2.WaitKey(0);
        }
    }
}
