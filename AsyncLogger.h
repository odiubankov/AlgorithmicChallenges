#ifndef ASYNC_LOGGER_H
#define ASYNC_LOGGER_H

#include <string>
#include <thread>
#include <queue>
#include <mutex>

namespace asynchronous{

  class AsyncLogger
  {
  public:
    static AsyncLogger& Instance();
    void log(const std::string& msg);

  private:
    void writeLog();

    AsyncLogger();
    ~AsyncLogger();
    AsyncLogger(const AsyncLogger&) = delete;
    AsyncLogger& operator=(const AsyncLogger&) = delete;

    std::queue<std::string> _msgQueue;
    std::mutex _mutex;
    std::condition_variable _condition;
    std::thread _writingThread;
  };

}//namespace asynchronous

#endif //ASYNC_LOGGER_H