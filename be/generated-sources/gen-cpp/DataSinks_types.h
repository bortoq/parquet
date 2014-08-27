/**
 * Autogenerated by Thrift Compiler (0.9.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef DataSinks_TYPES_H
#define DataSinks_TYPES_H

#include <thrift/Thrift.h>
#include <thrift/TApplicationException.h>
#include <thrift/protocol/TProtocol.h>
#include <thrift/transport/TTransport.h>

#include "Exprs_types.h"
#include "Types_types.h"
#include "Descriptors_types.h"
#include "Partitions_types.h"


namespace impala {

struct TDataSinkType {
  enum type {
    DATA_STREAM_SINK = 0,
    TABLE_SINK = 1
  };
};

extern const std::map<int, const char*> _TDataSinkType_VALUES_TO_NAMES;

struct TTableSinkType {
  enum type {
    HDFS = 0,
    HBASE = 1
  };
};

extern const std::map<int, const char*> _TTableSinkType_VALUES_TO_NAMES;


class TDataStreamSink {
 public:

  static const char* ascii_fingerprint; // = "89B3A468AE3D087BCD3327ECAD5B9AA0";
  static const uint8_t binary_fingerprint[16]; // = {0x89,0xB3,0xA4,0x68,0xAE,0x3D,0x08,0x7B,0xCD,0x33,0x27,0xEC,0xAD,0x5B,0x9A,0xA0};

  TDataStreamSink() : dest_node_id(0) {
  }

  virtual ~TDataStreamSink() throw() {}

   ::impala::TPlanNodeId dest_node_id;
   ::impala::TDataPartition output_partition;

  void __set_dest_node_id(const  ::impala::TPlanNodeId val) {
    dest_node_id = val;
  }

  void __set_output_partition(const  ::impala::TDataPartition& val) {
    output_partition = val;
  }

  bool operator == (const TDataStreamSink & rhs) const
  {
    if (!(dest_node_id == rhs.dest_node_id))
      return false;
    if (!(output_partition == rhs.output_partition))
      return false;
    return true;
  }
  bool operator != (const TDataStreamSink &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TDataStreamSink & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

void swap(TDataStreamSink &a, TDataStreamSink &b);


class THdfsTableSink {
 public:

  static const char* ascii_fingerprint; // = "88ABCD4E168E89EC92D6FDB8AEDA4AF4";
  static const uint8_t binary_fingerprint[16]; // = {0x88,0xAB,0xCD,0x4E,0x16,0x8E,0x89,0xEC,0x92,0xD6,0xFD,0xB8,0xAE,0xDA,0x4A,0xF4};

  THdfsTableSink() : overwrite(0) {
  }

  virtual ~THdfsTableSink() throw() {}

  std::vector< ::impala::TExpr>  partition_key_exprs;
  bool overwrite;

  void __set_partition_key_exprs(const std::vector< ::impala::TExpr> & val) {
    partition_key_exprs = val;
  }

  void __set_overwrite(const bool val) {
    overwrite = val;
  }

  bool operator == (const THdfsTableSink & rhs) const
  {
    if (!(partition_key_exprs == rhs.partition_key_exprs))
      return false;
    if (!(overwrite == rhs.overwrite))
      return false;
    return true;
  }
  bool operator != (const THdfsTableSink &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const THdfsTableSink & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

void swap(THdfsTableSink &a, THdfsTableSink &b);

typedef struct _TTableSink__isset {
  _TTableSink__isset() : hdfs_table_sink(false) {}
  bool hdfs_table_sink;
} _TTableSink__isset;

class TTableSink {
 public:

  static const char* ascii_fingerprint; // = "43EDF0A287D887048295E6E5F4FA2377";
  static const uint8_t binary_fingerprint[16]; // = {0x43,0xED,0xF0,0xA2,0x87,0xD8,0x87,0x04,0x82,0x95,0xE6,0xE5,0xF4,0xFA,0x23,0x77};

  TTableSink() : target_table_id(0), type((TTableSinkType::type)0) {
  }

  virtual ~TTableSink() throw() {}

   ::impala::TTableId target_table_id;
  TTableSinkType::type type;
  THdfsTableSink hdfs_table_sink;

  _TTableSink__isset __isset;

  void __set_target_table_id(const  ::impala::TTableId val) {
    target_table_id = val;
  }

  void __set_type(const TTableSinkType::type val) {
    type = val;
  }

  void __set_hdfs_table_sink(const THdfsTableSink& val) {
    hdfs_table_sink = val;
    __isset.hdfs_table_sink = true;
  }

  bool operator == (const TTableSink & rhs) const
  {
    if (!(target_table_id == rhs.target_table_id))
      return false;
    if (!(type == rhs.type))
      return false;
    if (__isset.hdfs_table_sink != rhs.__isset.hdfs_table_sink)
      return false;
    else if (__isset.hdfs_table_sink && !(hdfs_table_sink == rhs.hdfs_table_sink))
      return false;
    return true;
  }
  bool operator != (const TTableSink &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TTableSink & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

void swap(TTableSink &a, TTableSink &b);

typedef struct _TDataSink__isset {
  _TDataSink__isset() : stream_sink(false), table_sink(false) {}
  bool stream_sink;
  bool table_sink;
} _TDataSink__isset;

class TDataSink {
 public:

  static const char* ascii_fingerprint; // = "82F1D8DB434B35E65D20725B5BFDDD6A";
  static const uint8_t binary_fingerprint[16]; // = {0x82,0xF1,0xD8,0xDB,0x43,0x4B,0x35,0xE6,0x5D,0x20,0x72,0x5B,0x5B,0xFD,0xDD,0x6A};

  TDataSink() : type((TDataSinkType::type)0) {
  }

  virtual ~TDataSink() throw() {}

  TDataSinkType::type type;
  TDataStreamSink stream_sink;
  TTableSink table_sink;

  _TDataSink__isset __isset;

  void __set_type(const TDataSinkType::type val) {
    type = val;
  }

  void __set_stream_sink(const TDataStreamSink& val) {
    stream_sink = val;
    __isset.stream_sink = true;
  }

  void __set_table_sink(const TTableSink& val) {
    table_sink = val;
    __isset.table_sink = true;
  }

  bool operator == (const TDataSink & rhs) const
  {
    if (!(type == rhs.type))
      return false;
    if (__isset.stream_sink != rhs.__isset.stream_sink)
      return false;
    else if (__isset.stream_sink && !(stream_sink == rhs.stream_sink))
      return false;
    if (__isset.table_sink != rhs.__isset.table_sink)
      return false;
    else if (__isset.table_sink && !(table_sink == rhs.table_sink))
      return false;
    return true;
  }
  bool operator != (const TDataSink &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TDataSink & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

void swap(TDataSink &a, TDataSink &b);

} // namespace

#endif