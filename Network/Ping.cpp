#include "Ping.h"
#include <WinSock2.h>

using namespace NobelLib;
using namespace NobelLib::Net;
 /*
Ping::Ping(Network* connection)
{
	net_cNetwork = connection;
	sockaddr_in dest, source;
	if (setup_for_ping(argv[1], ttl, sd, dest) < 0) {
		goto cleanup;
	}
	if (allocate_buffers(send_buf, recv_buf, packet_size) < 0) {
		goto cleanup;
	}
	init_ping_packet(send_buf, packet_size, seq_no);

	// Send the ping and receive the reply
	if (send_ping(sd, dest, send_buf, packet_size) >= 0) {
		while (1) {
			// Receive replies until we either get a successful read,
			// or a fatal error occurs.
			if (recv_ping(sd, source, recv_buf, MAX_PING_PACKET_SIZE) <
				0) {
				// Pull the sequence number out of the ICMP header.  If 
				// it's bad, we just complain, but otherwise we take 
				// off, because the read failed for some reason.
				unsigned short header_len = recv_buf->h_len * 4;
				ICMPHeader* icmphdr = (ICMPHeader*)
					((char*)recv_buf + header_len);
				if (icmphdr->seq != seq_no) {
					cerr << "bad sequence number!" << endl;
					continue;
				}
				else {
					break;
				}
			}
			if (decode_reply(recv_buf, packet_size, &source) != -2) {
				// Success or fatal error (as opposed to a minor error) 
				// so take off.
				break;
			}
		}
	}
}
*/