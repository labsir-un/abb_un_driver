// Generated by gencpp from file abb_robot_msgs/RAPIDSymbolPath.msg
// DO NOT EDIT!


#ifndef ABB_ROBOT_MSGS_MESSAGE_RAPIDSYMBOLPATH_H
#define ABB_ROBOT_MSGS_MESSAGE_RAPIDSYMBOLPATH_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace abb_robot_msgs
{
template <class ContainerAllocator>
struct RAPIDSymbolPath_
{
  typedef RAPIDSymbolPath_<ContainerAllocator> Type;

  RAPIDSymbolPath_()
    : task()
    , module()
    , symbol()  {
    }
  RAPIDSymbolPath_(const ContainerAllocator& _alloc)
    : task(_alloc)
    , module(_alloc)
    , symbol(_alloc)  {
  (void)_alloc;
    }



   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _task_type;
  _task_type task;

   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _module_type;
  _module_type module;

   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _symbol_type;
  _symbol_type symbol;





  typedef boost::shared_ptr< ::abb_robot_msgs::RAPIDSymbolPath_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::abb_robot_msgs::RAPIDSymbolPath_<ContainerAllocator> const> ConstPtr;

}; // struct RAPIDSymbolPath_

typedef ::abb_robot_msgs::RAPIDSymbolPath_<std::allocator<void> > RAPIDSymbolPath;

typedef boost::shared_ptr< ::abb_robot_msgs::RAPIDSymbolPath > RAPIDSymbolPathPtr;
typedef boost::shared_ptr< ::abb_robot_msgs::RAPIDSymbolPath const> RAPIDSymbolPathConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::abb_robot_msgs::RAPIDSymbolPath_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::abb_robot_msgs::RAPIDSymbolPath_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::abb_robot_msgs::RAPIDSymbolPath_<ContainerAllocator1> & lhs, const ::abb_robot_msgs::RAPIDSymbolPath_<ContainerAllocator2> & rhs)
{
  return lhs.task == rhs.task &&
    lhs.module == rhs.module &&
    lhs.symbol == rhs.symbol;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::abb_robot_msgs::RAPIDSymbolPath_<ContainerAllocator1> & lhs, const ::abb_robot_msgs::RAPIDSymbolPath_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace abb_robot_msgs

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::abb_robot_msgs::RAPIDSymbolPath_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::abb_robot_msgs::RAPIDSymbolPath_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::abb_robot_msgs::RAPIDSymbolPath_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::abb_robot_msgs::RAPIDSymbolPath_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::abb_robot_msgs::RAPIDSymbolPath_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::abb_robot_msgs::RAPIDSymbolPath_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::abb_robot_msgs::RAPIDSymbolPath_<ContainerAllocator> >
{
  static const char* value()
  {
    return "3214a5a49942fc04a524a160d9874980";
  }

  static const char* value(const ::abb_robot_msgs::RAPIDSymbolPath_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x3214a5a49942fc04ULL;
  static const uint64_t static_value2 = 0xa524a160d9874980ULL;
};

template<class ContainerAllocator>
struct DataType< ::abb_robot_msgs::RAPIDSymbolPath_<ContainerAllocator> >
{
  static const char* value()
  {
    return "abb_robot_msgs/RAPIDSymbolPath";
  }

  static const char* value(const ::abb_robot_msgs::RAPIDSymbolPath_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::abb_robot_msgs::RAPIDSymbolPath_<ContainerAllocator> >
{
  static const char* value()
  {
    return "#-------------------------------------------------------------------------------\n"
"# Description:\n"
"#   The purpose of this message definition, is to represent the path to a RAPID\n"
"#   symbol (e.g. a variable) defined in an ABB robot controller system.\n"
"#-------------------------------------------------------------------------------\n"
"\n"
"#-------------------------------------------------------------------------------\n"
"# Message fields\n"
"#-------------------------------------------------------------------------------\n"
"# Name of the RAPID task, where the symbol exists (i.e. the symbol's context).\n"
"string task\n"
"\n"
"# Name of the RAPID module, where the symbol has been defined.\n"
"string module\n"
"\n"
"# Name of the RAPID symbol in question.\n"
"string symbol\n"
;
  }

  static const char* value(const ::abb_robot_msgs::RAPIDSymbolPath_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::abb_robot_msgs::RAPIDSymbolPath_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.task);
      stream.next(m.module);
      stream.next(m.symbol);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct RAPIDSymbolPath_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::abb_robot_msgs::RAPIDSymbolPath_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::abb_robot_msgs::RAPIDSymbolPath_<ContainerAllocator>& v)
  {
    s << indent << "task: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.task);
    s << indent << "module: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.module);
    s << indent << "symbol: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.symbol);
  }
};

} // namespace message_operations
} // namespace ros

#endif // ABB_ROBOT_MSGS_MESSAGE_RAPIDSYMBOLPATH_H