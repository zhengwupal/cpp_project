#include "pro/module_a/abc.h"

#include <concurrentqueue.h>
#include <fmt/core.h>
#include <readerwritercircularbuffer.h>
#include <readerwriterqueue.h>

#include <boost/asio.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/regex.hpp>
#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <thread>

using namespace moodycamel;

// a hack square root calculation using simple operations
double mysqrt(double x) {
  if (x <= 0) {
    return 0;
  }

  double result = x;

  // do ten iterations
  for (int i = 0; i < 10; ++i) {
    if (result <= 0) {
      result = 0.1;
    }
    double delta = x - (result * result);
    result = result + 0.5 * delta / result;
    // std::cout << "Computing sqrt of " << x << " to be " << result <<
    // std::endl;
  }
  int *a = new int(3);
  std::cout << "a: " << *a << std::endl;
  return result;
}

void test1() {
  boost::regex re("(https?://www.ttufo.com/.+/.+/.+)(_\\d+)(.html?)");

  // string replace("http://www.ttufo.com/($1)/($2)/($3).htm($5)");
  // regex re("http://www.ttufo.com/(.+)/(.+)/(.+)(_.+).htm(l?)");

  std::string target("http://www.ttufo.com/ufo/201705/154053_3.html");

  boost::cmatch what;

  if (boost::regex_match(target.c_str(), what, re)) {
    std::cout << "match " << what.size() << std::endl;

    for (int i = 0; i < what.size(); i++) {
      std::cout << "what[" << i << "]: " << what[i]
                << ", first: " << what[i].first
                << ", second: " << what[i].second << std::endl;
    }
  } else {
    std::cout << "not match " << std::endl;
  }

  std::cout << "=====" << std::endl;

  boost::posix_time::time_duration td(1, 2, 3, 888);
  std::cout << td << std::endl;
}

void test3() {
  std::string s("1/1/1900");
  if (s.find("/") != std::string::npos) {
    std::cout << "found" << std::endl;
  }
}

void test4() {
  std::string expression{"This is (pezy)."};
  bool bSeen = false;
  std::stack<char> stk;
  for (const auto &s : expression) {
    if (s == '(') {
      bSeen = true;
      continue;
    } else if (s == ')')
      bSeen = false;

    if (bSeen) stk.push(s);
  }

  std::string repstr;
  while (!stk.empty()) {
    repstr += stk.top();
    stk.pop();
  }

  expression.replace(expression.find("(") + 1, repstr.size(), repstr);

  std::cout << expression << std::endl;
}

void test5() {
  std::map<std::string, size_t> counts;
  std::string word("abc");
  auto result = counts.insert({word, 1});  // result is pair
  std::cout << result.first->second << std::endl;
}

void test6() {
  ReaderWriterQueue<int> q(
      8);  // Reserve space for at least 100 elements up front

  // q.enqueue(17);  // Will allocate memory if the queue is full
  // bool succeeded = q.try_enqueue(18);  // Will only succeed if the queue has
  // an
  //                                      // empty slot (never allocates)

  for (size_t i = 0; i < 18; i++) {
    std::cout << q.max_capacity() << std::endl;
    std::cout << q.size_approx() << std::endl;
    if (q.try_enqueue(i)) {
      std::cout << i << " enter queue success" << std::endl;
    } else {
      std::cout << i << " enter queue fail" << std::endl;
    }
  }

  int number;
  bool succeeded =
      q.try_dequeue(number);  // Returns false if the queue was empty

  // assert(succeeded && number == 17);

  // // You can also peek at the front item of the queue (consumer only)
  // int *front = q.peek();
  // assert(*front == 18);
  // succeeded = q.try_dequeue(number);
  // assert(succeeded && number == 18);
  // front = q.peek();
  // assert(front == nullptr);  // Returns nullptr if the queue was empty
}

void test7() {
  std::cout << "BlockingReaderWriterQueue" << std::endl;
  BlockingReaderWriterQueue<int> q;

  std::thread reader([&]() {
    int item;
#if 0
    // for (int i = 0; i != 100; ++i) {
    //   // Fully-blocking:
    //   q.wait_dequeue(item);
    //   std::cout << item << " out queue success" << std::endl;
    // }

    while (true) {
      q.wait_dequeue(item);
      std::cout << item << " out queue success" << std::endl;
    }

#else
    // for (int i = 0; i != 100;) {
    //   // Blocking with timeout
    //   if (q.wait_dequeue_timed(item, std::chrono::milliseconds(5))) ++i;
    // }

    while (true) {
      if (q.wait_dequeue_timed(item, std::chrono::milliseconds(5000))) {
        std::cout << item << " out queue success" << std::endl;
      } else {
        std::cout << "timeout" << std::endl;
        break;
      }
    }
#endif
  });
  std::thread writer([&]() {
    for (int i = 0; i != 10; ++i) {
      std::cout << i << " enter queue success" << std::endl;
      q.enqueue(i);
      std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
  });
  writer.join();
  reader.join();

  assert(q.size_approx() == 0);
}

void test8() {
  std::cout << "BlockingReaderWriterCircularBuffer" << std::endl;
  BlockingReaderWriterCircularBuffer<int> q(8);  // pass initial capacity

  // q.try_enqueue(1);
  // int number;
  // q.try_dequeue(number);
  // assert(number == 1);

  // q.wait_enqueue(123);
  // q.wait_dequeue(number);
  // assert(number == 123);

  // q.wait_dequeue_timed(number, std::chrono::milliseconds(10));

  std::thread reader([&]() {
    int item;
#if 0
    // for (int i = 0; i != 100; ++i) {
    //   // Fully-blocking:
    //   q.wait_dequeue(item);
    //   std::cout << item << " out queue success" << std::endl;
    // }

    while (true) {
      q.wait_dequeue(item);
      std::cout << item << " out queue success" << std::endl;
    }

#else
    // for (int i = 0; i != 100;) {
    //   // Blocking with timeout
    //   if (q.wait_dequeue_timed(item, std::chrono::milliseconds(5))) ++i;
    // }

    while (true) {
      if (q.wait_dequeue_timed(item, std::chrono::milliseconds(5000))) {
        std::cout << item << " out queue success" << std::endl;
      } else {
        std::cout << "timeout" << std::endl;
        break;
      }
    }
#endif
  });
  std::thread writer([&]() {
    for (int i = 0; i != 10; ++i) {
      std::cout << i << " enter queue success" << std::endl;
      q.try_enqueue(i);
      std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
  });
  writer.join();
  reader.join();

  assert(q.size_approx() == 0);
}

void test9() {
  ConcurrentQueue<int> q;
  int dequeued[100] = {0};
  std::thread threads[20];

  // Producers
  for (int i = 0; i != 10; ++i) {
    threads[i] = std::thread(
        [&](int i) {
          for (int j = 0; j != 10; ++j) {
            q.enqueue(i * 10 + j);
          }
        },
        i);
  }

  // Consumers
  for (int i = 10; i != 20; ++i) {
    threads[i] = std::thread([&]() {
      int item;
      for (int j = 0; j != 20; ++j) {
        if (q.try_dequeue(item)) {
          ++dequeued[item];
        }
      }
    });
  }

  // Wait for all threads
  for (int i = 0; i != 20; ++i) {
    threads[i].join();
  }

  // Collect any leftovers (could be some if e.g. consumers finish before
  // producers)
  int item;
  while (q.try_dequeue(item)) {
    ++dequeued[item];
    fmt::print("item: {}\n", item);
  }

  // Make sure everything went in and came back out!
  for (int i = 0; i != 100; ++i) {
    assert(dequeued[i] == 1);
    fmt::print("dequeued[{}]: {}\n", i, dequeued[i]);
  }
}

void test10() {
  ConcurrentQueue<int> q;
  const int ProducerCount = 4;
  const int ConsumerCount = 4;
  std::thread producers[ProducerCount];
  std::thread consumers[ConsumerCount];
  std::atomic<int> doneProducers(0);
  std::atomic<int> doneConsumers(0);
  for (int i = 0; i != ProducerCount; ++i) {
    producers[i] = std::thread([&]() {
      for (size_t i = 0; i < 100; i++) {
        q.enqueue(i);
      }
      doneProducers.fetch_add(1, std::memory_order_release);
    });
  }
  for (int i = 0; i != ConsumerCount; ++i) {
    consumers[i] = std::thread([&]() {
      int item;
      bool itemsLeft;
      do {
        // It's important to fence (if the producers have finished) *before*
        // dequeueing
        fmt::print("doneConsumers: {}\n", doneConsumers);
        itemsLeft =
            doneProducers.load(std::memory_order_acquire) != ProducerCount;
        while (q.try_dequeue(item)) {
          itemsLeft = true;
          // fmt::print("item: {}\n", item);
        }
      } while (itemsLeft ||
               doneConsumers.fetch_add(1, std::memory_order_acq_rel) + 1 ==
                   ConsumerCount);
      // The condition above is a bit tricky, but it's necessary to ensure that
      // the last consumer sees the memory effects of all the other consumers
      // before it calls try_dequeue for the last time
    });
  }
  for (int i = 0; i != ProducerCount; ++i) {
    producers[i].join();
  }
  for (int i = 0; i != ConsumerCount; ++i) {
    consumers[i].join();
  }
}

void test11() {
  fmt::print("boost::asio\n");
  boost::asio::thread_pool pool(4);
  boost::asio::post(pool, test3);
  boost::asio::post(pool, test4);
  boost::asio::post(pool, test5);
  pool.join();
}

void no_poly() {}

void poly() {}