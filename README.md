# data-queue-dispatch-threads
多线程间数据对象分发，带share_ptr方式
数据对象用模板表示，支持多线程
生产者将对象放入到队列中，消费者通过阻塞接口等待condtion，消费者可获得对象的引用，或者封装shared ptr之后的指针。
