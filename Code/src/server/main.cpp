#include <iostream>
#include <asio.hpp>

std::string read(asio::ip::tcp::socket& socket) {
	asio::streambuf buf;
	asio::read_until(socket, buf, '\n');
	return std::string(asio::buffer_cast<const char*>(buf.data()), buf.size());
}

void write(asio::ip::tcp::socket& socket, const std::string& msg) {
	asio::write(socket, asio::buffer(msg));
}

int main(int argc, char** argv) {
	asio::io_service io_service;
	asio::ip::tcp::acceptor acceptor(io_service, asio::ip::tcp::endpoint(asio::ip::tcp::v4(), 6942));
	asio::ip::tcp::socket socket(io_service);
	acceptor.accept(socket);
	std::cout << "Connected" << std::endl;
	std::string msg = read(socket);
	std::cout << "Received: " << msg << std::endl;
	write(socket, "Hello, !");
	return 0;
}