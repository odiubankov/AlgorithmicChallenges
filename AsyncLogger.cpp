#include "AsyncLogger.h"
#include <gtest/gtest.h>

namespace {
  static const std::string STOP_LOGGING_MSG = "{34EA1AB3-E76E-4C41-9F07-5803EEC9D567}";
}

namespace asynchronous {

  AsyncLogger& AsyncLogger::Instance()
  {
    static AsyncLogger asyncLogger;
    return asyncLogger;
  }


  AsyncLogger::AsyncLogger()
    : _msgQueue{}
    , _mutex{}
    , _condition{}
    , _writingThread{ [this]() { writeLog(); } }
  {}


  AsyncLogger::~AsyncLogger()
  {
    log(STOP_LOGGING_MSG);
    _writingThread.join();
  }


  void AsyncLogger::log(const std::string& msg)
  {
    {
      std::unique_lock<std::mutex> lock{ _mutex };
      _msgQueue.push(msg);
    }

    _condition.notify_one();
  }


  void AsyncLogger::writeLog()
  {
    std::string nextMsg;
    for(;;)
    {
      {
        std::unique_lock<std::mutex> lock{ _mutex };
        _condition.wait(lock, [this]() { return !_msgQueue.empty(); });
        nextMsg = _msgQueue.front();
        _msgQueue.pop();
      }

      if (nextMsg == STOP_LOGGING_MSG)
        break;

      std::cout << nextMsg << std::endl;
    }
  }


  TEST(AsyncLogger, test)
  {
    std::vector<std::thread> _threads;
    for (auto i = 0; i < 10000; ++i)
    {
      _threads.emplace_back( [i](){ AsyncLogger::Instance().log(std::to_string(i)); } );
    }

    for (auto& thread : _threads)
      thread.join();
  }

}//namespace asynchronous