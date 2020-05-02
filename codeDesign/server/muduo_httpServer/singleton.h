#ifndef MUDUO_HTTP_SINGLETON_
#define MUDUO_HTTP_SINGLETON_

#include <mutex>
template<class T>
class Singleton
{
public:
    static T* instance()
    {
        if(instance_ == nullptr)
        {
            std::lock_guard<std::mutex> lock(mutex_create_instance_);
            if(instance_ == nullptr)
            {
                instance_ = new T;
            }
        }
        return instance_;
    }
    static void destroy()
    {
        if(instance_ != nullptr)
        {
           delete instance_;
           instance_ = nullptr;
        }
    }

protected:
    Singleton(){};
    ~Singleton(){};

    Singleton(const Singleton&);
    Singleton& operator =(const Singleton&);
private:
    static T* instance_;
    static std::mutex mutex_create_instance_;
}
#endif // !MUDUO_HTTP_SINGLETON_
