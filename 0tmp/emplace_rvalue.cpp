// cesun, 11/7/20 9:25 PM.

#include <vector>
#include <thread>
#include <mutex>

class Foo {
private:
    std::vector<int> xg;
public:
    Foo(){}
};

void bar(int c, Foo foo){

}

class Config {
public:
    int getPort(){return 42;}
};
class SessionManager {
private:
    std::vector<int> ss;
    std::mutex m;
public:
    SessionManager() {

    }

    void emplaceSession(int conn) {
//        m.lock();
//        ss.emplace_back(conn);
//        m.unlock();
    }
};

[[noreturn]] void server(int port, SessionManager sm) {
    int acc{port};
    while (true) {

    }
}

int main() {
    Config config;
    SessionManager sm{};
    std::thread server_thread{server, config.getPort(), sm};
}
