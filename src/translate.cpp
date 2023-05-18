#include "translate.hpp"

namespace http = boost::beast::http;

string translate(string str)
{
    string translateAPI = R"(translate.yandex.net)";
    string API_ARGS = R"(/api/v1.5/tr.json/translate)";
    string API_KEY = R"(тут будет ключ)";

    boost::asio::io_context io;
    boost::asio::ip::tcp::socket socket(io);
    boost::asio::ip::tcp::resolver resolver(io);

    boost::asio::connect(socket, resolver.resolve(translateAPI, "80"));

    string argument = API_ARGS + 
        "?key=" + API_KEY +
        "&text=" + str +
        "&lang=" + "en-ru";

    http::request<http::string_body> req(http::verb::get, argument, 11);

    req.set(http::field::host, translateAPI);
    req.set(http::field::user_agent, BOOST_BEAST_VERSION_STRING);

    http::write(socket, req);

    string response;
    {
        boost::beast::flat_buffer buffer;
        http::response<http::dynamic_body> res;
        http::read(socket, buffer, res);
        response = boost::beast::buffers_to_string(res.body().data());
    }

    socket.shutdown(boost::asio::ip::tcp::socket::shutdown_both);
    cout << response;

    return str;
}