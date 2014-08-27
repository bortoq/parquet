// Copyright 2012 Cloudera Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.


#ifndef IMPALA_UTIL_DECOMPRESS_H
#define IMPALA_UTIL_DECOMPRESS_H

// We need zlib.h here to declare stream_ below.
#include <zlib.h>

#include "util/codec.h"
#include "exec/hdfs-scanner.h"
#include "runtime/mem-pool.h"

namespace impala {

class GzipDecompressor : public Codec {
 public:
  virtual ~GzipDecompressor();
  virtual int MaxOutputLen(int input_len, const uint8_t* input = NULL);
  virtual Status ProcessBlock(bool output_preallocated,
                              int input_length, uint8_t* input,
                              int* output_length, uint8_t** output);

 private:
  friend class Codec;
  GzipDecompressor(
      MemPool* mem_pool = NULL, bool reuse_buffer = false, bool is_deflate = false);
  virtual Status Init();

  // If set assume deflate format, otherwise zlib or gzip
  bool is_deflate_;

  z_stream stream_;

  // These are magic numbers from zlib.h.  Not clear why they are not defined there.
  const static int WINDOW_BITS = 15;    // Maximum window size
  const static int DETECT_CODEC = 32;   // Determine if this is libz or gzip from header.
};

class BzipDecompressor : public Codec {
 public:
  virtual ~BzipDecompressor() { }
  virtual int MaxOutputLen(int input_len, const uint8_t* input = NULL);
  virtual Status ProcessBlock(bool output_preallocated,
                              int input_length, uint8_t* input,
                              int* output_length, uint8_t** output);
 private:
  friend class Codec;
  BzipDecompressor(MemPool* mem_pool, bool reuse_buffer);

  virtual Status Init() { return Status::OK; }
};

class SnappyDecompressor : public Codec {
 public:
  virtual ~SnappyDecompressor() { }
  virtual int MaxOutputLen(int input_len, const uint8_t* input = NULL);
  virtual Status ProcessBlock(bool output_preallocated,
                              int input_length, uint8_t* input,
                              int* output_length, uint8_t** output);

 private:
  friend class Codec;
  SnappyDecompressor(MemPool* mem_pool = NULL, bool reuse_buffer = false);
  virtual Status Init() { return Status::OK; }
};

// Lz4 is a compression codec with similar compression ratios as snappy but much faster 
// decompression. This decompressor is not able to decompress unless the output buffer
// is allocated and will cause an error if asked to do so.
class Lz4Decompressor : public Codec {
 public:
  virtual ~Lz4Decompressor() { }
  virtual int MaxOutputLen(int input_len, const uint8_t* input = NULL);
  virtual Status ProcessBlock(bool output_preallocated,
                              int input_length, uint8_t* input,
                              int* output_length, uint8_t** output);

 private:
  friend class Codec;
  Lz4Decompressor(MemPool* mem_pool = NULL, bool reuse_buffer = false);
  virtual Status Init() { return Status::OK; }
};

class SnappyBlockDecompressor : public Codec {
 public:
  virtual ~SnappyBlockDecompressor() { }
  virtual int MaxOutputLen(int input_len, const uint8_t* input = NULL);
  virtual Status ProcessBlock(bool output_preallocated,
                              int input_length, uint8_t* input,
                              int* output_length, uint8_t** output);

 private:
  friend class Codec;
  SnappyBlockDecompressor(MemPool* mem_pool, bool reuse_buffer);
  virtual Status Init() { return Status::OK; }
};

}
#endif
