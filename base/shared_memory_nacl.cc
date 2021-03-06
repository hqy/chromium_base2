// Copyright (c) 2012 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "base/shared_memory.h"

#include <errno.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>

#include "base/logging.h"

namespace base {

SharedMemory::SharedMemory()
    : mapped_file_(-1),
      mapped_size_(0),
      inode_(0),
      memory_(NULL),
      read_only_(false),
      created_size_(0) {
}

SharedMemory::SharedMemory(SharedMemoryHandle handle, bool read_only)
    : mapped_file_(handle.fd),
      mapped_size_(0),
      inode_(0),
      memory_(NULL),
      read_only_(read_only),
      created_size_(0) {
}

SharedMemory::SharedMemory(SharedMemoryHandle handle, bool read_only,
                           ProcessHandle process)
    : mapped_file_(handle.fd),
      mapped_size_(0),
      inode_(0),
      memory_(NULL),
      read_only_(read_only),
      created_size_(0) {
  NOTREACHED();
}

SharedMemory::~SharedMemory() {
  Close();
}

// static
bool SharedMemory::IsHandleValid(const SharedMemoryHandle& handle) {
  return handle.fd >= 0;
}

// static
SharedMemoryHandle SharedMemory::NULLHandle() {
  return SharedMemoryHandle();
}

// static
void SharedMemory::CloseHandle(const SharedMemoryHandle& handle) {
  DCHECK_GE(handle.fd, 0);
  if (close(handle.fd) < 0)
    DPLOG(ERROR) << "close";
}

bool SharedMemory::CreateAndMapAnonymous(uint32 size) {
  // Untrusted code can't create descriptors or handles.
  return false;
}

bool SharedMemory::Create(const SharedMemoryCreateOptions& options) {
  // Untrusted code can't create descriptors or handles.
  return false;
}

bool SharedMemory::Delete(const std::string& name) {
  return false;
}

bool SharedMemory::Open(const std::string& name, bool read_only) {
  return false;
}

bool SharedMemory::Map(uint32 bytes) {
  if (mapped_file_ == -1)
    return false;

  memory_ = mmap(NULL, bytes, PROT_READ | (read_only_ ? 0 : PROT_WRITE),
                 MAP_SHARED, mapped_file_, 0);

  bool mmap_succeeded = memory_ != MAP_FAILED && memory_ != NULL;
  if (mmap_succeeded)
    mapped_size_ = bytes;
  else
    memory_ = NULL;

  return mmap_succeeded;
}

bool SharedMemory::Unmap() {
  if (memory_ == NULL)
    return false;

  if (munmap(memory_, mapped_size_) < 0)
    DPLOG(ERROR) << "munmap";
  memory_ = NULL;
  mapped_size_ = 0;
  return true;
}

SharedMemoryHandle SharedMemory::handle() const {
  return FileDescriptor(mapped_file_, false);
}

void SharedMemory::Close() {
  Unmap();

  if (mapped_file_ > 0) {
    if (close(mapped_file_) < 0)
      DPLOG(ERROR) << "close";
    mapped_file_ = -1;
  }
}

void SharedMemory::Lock() {
  NOTIMPLEMENTED();
}

void SharedMemory::Unlock() {
  NOTIMPLEMENTED();
}

bool SharedMemory::ShareToProcessCommon(ProcessHandle process,
                                        SharedMemoryHandle *new_handle,
                                        bool close_self) {
  return false;
}

}  // namespace base
