WARNING: VS2022 doesn't support c++11 mode, if you just install the normal c++ desktop workload. install these two additional things:

- MSVC v140....
- Windows Universal C Runtime

google search: "when to write move constructor"

https://stackoverflow.com/a/52888229

https://en.cppreference.com/w/cpp/language/rule_of_three

when are user-defined destructor / copy constructor / copy assignment needed?

when are user-defined move constructor needed / move assignment needed in addition?


The implicitly-defined special member functions are typically incorrect if the class manages a resource whose handle is an object of non-class type (raw pointer, POSIX file descriptor, etc), whose destructor does nothing and copy constructor/assignment operator performs a "shallow copy" (copy the value of the handle, without duplicating the underlying resource).


Because the presence of a user-defined (or = default or = delete declared) destructor, copy-constructor, or copy-assignment operator prevents implicit definition of the move constructor and the move assignment operator, any class for which move semantics are desirable, has to declare all five special member functions:



Classes that have custom destructors, copy/move constructors or copy/move assignment operators should deal exclusively with ownership


