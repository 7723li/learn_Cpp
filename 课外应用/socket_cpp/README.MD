socket即套接字，用于描述地址和端口，是一个通信链的句柄。应用程序通过socket向网络发出请求或者回应。

sockets(套接字)编程有三种，流式套接字（SOCK_STREAM），数据报套接字（SOCK_DGRAM），原始套接字（SOCK_RAW）；前两种较常用。基于TCP的socket编程是采用的流式套接字。

1) SOCK_STREAM表示面向连接的数据传输方式。数据可以准确无误地到达另一台计算机，如果损坏或丢失，可以重新发送，但效率相对较慢。常用的HTTP协议就使用SOCK_STREAM传输数据，因
为要确保数据的正确性，否则网页不能正常解析。

2) SOCK_DGRAM表示无连接的数据传输方式。计算机只管传输数据，不作数据校验，如果数据在传输中损坏，或者没有到达另一台计算机，是没有办法补救的。也就是说，数据错了就错了，
无法重传。因为SOCK_DGRAM所做的校验工作少，所以效率比SOCK_STREAM高。

<a href = "https://blog.csdn.net/li_ning_/article/details/52117463">TCP和UDP的最完整的区别</a>