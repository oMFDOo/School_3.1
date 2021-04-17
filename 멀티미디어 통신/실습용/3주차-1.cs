using System;
using System.IO;
using System.Net;
using System.Net.Sockets;
using System.Text;

namespace 실습용
{
    class Program
    {
        static void Main(string[] args)
        {
            //// 호스트명으로 IP 주소 얻어내기
            //IPHostEntry host = Dns.GetHostEntry("www.deu.ac.kr");
            //Console.WriteLine("host to ip : " + host.HostName);
            //foreach (IPAddress ip in host.AddressList)
            //{
            //    Console.WriteLine(ip);
            //}

            //// IP주소로 호스트명 얻어내기
            //IPAddress ipAdr = IPAddress.Parse("113.198.254.51");
            //IPHostEntry host2 = Dns.GetHostEntry(ipAdr);
            //Console.WriteLine("ip to host : " + host2.HostName);
            ////Console.WriteLine(host2.AddressList);

            // 포트를 통해 접근하기
            //IPAddress ip = IPAddress.Parse("127.0.0.1");
            //IPEndPoint ep = new IPEndPoint(ip, 80);
            //Console.WriteLine(ep.ToString());


            //// TCP통신 : 통신망을 통해서 로컬호스트 접근
            //TcpClient tcp = new TcpClient("127.0.0.1", 9100);
            //// 9100 포트 사용

            //string msg = "통신 수행 중";
            //// 메시지 지정

            //byte[] buffers = Encoding.UTF8.GetBytes(msg);
            //// 바이트 단위로 데이터를 받고 UTF8로 인코딩

            //NetworkStream stream = tcp.GetStream();

            //stream.Write(buffers, 0, buffers.Length);
            //// stream에 0부터 버퍼 길이까지 작성

            //byte[] outbuf = new byte[512];
            //int nbytes = stream.Read(outbuf, 0, outbuf.Length);
            //// stream에 0부터 버퍼 길이까지 읽음

            //string output = Encoding.UTF8.GetString(outbuf, 0, nbytes);

            //stream.Close();
            //tcp.Close();

            //Console.WriteLine(msg);
            //Console.WriteLine(output);

            // 안정적으로 데이터를 받아오는 방법
            //MemoryStream mem = new MemoryStream();
            //while ((nbytes = stream.Read(outbuf, 0, outbuf.Length)) > 0)
            //{
            //    mem.Write(outbuf, 0, nbytes);
            //}

            // Listener 구현
            // (1) 로컬포트 9100 Listen
            TcpListener listener = new TcpListener(IPAddress.Any, 9100); 
            listener.Start();
            byte[] buff = new byte[1024];
            while (true)
            {
                // (2) TcpClient Connection 요청 받아서 서버에서 새 TcpClient 객체 생성
                TcpClient tc = listener.AcceptTcpClient();
                // (3) TcpClient 객체에서 NetworkStream을 얻어옴
                NetworkStream stream = tc.GetStream();
                // (4) 클라이언트가 연결을 끊을 때까지 데이터 수신
            }
        }
    }
}
