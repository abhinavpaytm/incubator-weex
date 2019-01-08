/*
 * Copyright (C) 2008 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/*
 * Implementation of the user-space ashmem API for devices, which have our
 * ashmem-enabled kernel. See ashmem-sim.c for the "fake" tmp-based version,
 * used by the simulator.
 */

#ifndef IPCEXCEPTION_H
#define IPCEXCEPTION_H
#include <memory>

class IPCException {
public:
    IPCException(const char* fmt, ...);
    ~IPCException();
    IPCException(IPCException&& ex);
    const char* msg() const;

private:
    struct IPCExceptionImpl;
    std::unique_ptr<IPCExceptionImpl> m_impl;
};
#endif /* IPCEXCEPTION_H */
