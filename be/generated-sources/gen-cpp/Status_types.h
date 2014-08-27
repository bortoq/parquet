/**
 * Autogenerated by Thrift Compiler (0.9.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef Status_TYPES_H
#define Status_TYPES_H

#include <thrift/Thrift.h>
#include <thrift/TApplicationException.h>
#include <thrift/protocol/TProtocol.h>
#include <thrift/transport/TTransport.h>



namespace impala {

struct TStatusCode {
  enum type {
    OK = 0,
    CANCELLED = 1,
    ANALYSIS_ERROR = 2,
    NOT_IMPLEMENTED_ERROR = 3,
    RUNTIME_ERROR = 4,
    MEM_LIMIT_EXCEEDED = 5,
    INTERNAL_ERROR = 6,
    RECOVERABLE_ERROR = 7
  };
};

extern const std::map<int, const char*> _TStatusCode_VALUES_TO_NAMES;

typedef struct _TStatus__isset {
  _TStatus__isset() : error_msgs(false) {}
  bool error_msgs;
} _TStatus__isset;

class TStatus {
 public:

  static const char* ascii_fingerprint; // = "A22BE3E84688C9DA4E00CC902B4EE818";
  static const uint8_t binary_fingerprint[16]; // = {0xA2,0x2B,0xE3,0xE8,0x46,0x88,0xC9,0xDA,0x4E,0x00,0xCC,0x90,0x2B,0x4E,0xE8,0x18};

  TStatus() : status_code((TStatusCode::type)0) {
  }

  virtual ~TStatus() throw() {}

  TStatusCode::type status_code;
  std::vector<std::string>  error_msgs;

  _TStatus__isset __isset;

  void __set_status_code(const TStatusCode::type val) {
    status_code = val;
  }

  void __set_error_msgs(const std::vector<std::string> & val) {
    error_msgs = val;
    __isset.error_msgs = true;
  }

  bool operator == (const TStatus & rhs) const
  {
    if (!(status_code == rhs.status_code))
      return false;
    if (!(error_msgs == rhs.error_msgs))
      return false;
    return true;
  }
  bool operator != (const TStatus &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TStatus & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

void swap(TStatus &a, TStatus &b);

} // namespace

#endif