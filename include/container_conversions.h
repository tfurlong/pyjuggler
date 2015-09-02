#ifndef _PYJ_CONTAINER_CONVERSIONS_H_
#define _PYJ_CONTAINER_CONVERSIONS_H_

#include <boost/python/list.hpp>
#include <boost/python/to_python_converter.hpp>
#include <boost/type_traits.hpp>

namespace pyj
{

// This is adapted from scitbx::boost_python::container_conversions::to_tuple,
// the source for which can be found at http://cctbx.sourceforge.net/
template<typename ContainerType, typename PythonType>
struct container_to_python
{
   static PyObject* convert(ContainerType const& a)
   {
      boost::python::list result;
      typedef typename ContainerType::const_iterator const_iter;
      for ( const_iter p = a.begin(); p != a.end(); ++p )
      {
         result.append(boost::python::object(*p));
      }
      return boost::python::incref(PythonType(result).ptr());
   }
};

template<typename ContainerType, typename PythonType>
struct container_to_python_noncopyable
{
   static PyObject* convert(ContainerType const& a)
   {
      boost::python::list result;
      typedef typename ContainerType::const_iterator const_iter;
      for ( const_iter p = a.begin(); p != a.end(); ++p )
      {
         result.append(boost::python::object(boost::python::ptr(*p)));
      }
      return boost::python::incref(PythonType(result).ptr());
   }
};

/**
 * \p PythonType must be convertible from boost::python::list. Suitable
 * values are boost::python::list and boost::python::tuple.
 */
template<typename ContainerType, typename PythonType>
struct copyable_to_python
{
   copyable_to_python()
   {
      boost::python::to_python_converter<
         ContainerType, container_to_python<ContainerType, PythonType>
      >();
   }
};

/**
 * \p PythonType must be convertible from boost::python::list. Suitable
 * values are boost::python::list and boost::python::tuple.
 */
template<typename ContainerType, typename PythonType>
struct noncopyable_to_python
{
   noncopyable_to_python()
   {
      boost::python::to_python_converter<
         ContainerType,
         container_to_python_noncopyable<ContainerType, PythonType>
      >();
   }
};

} // namespace pyj

#endif /* _PYJ_CONTAINER_CONVERSIONS_H_ */
