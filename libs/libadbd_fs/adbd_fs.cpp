/*
 * Copyright (C) 2020 The Android Open Source Project
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

#include <adbd_fs.h>

#include <private/fs_config.h>
#include <unistd.h>

void adbd_fs_config(const char* path, int dir, const char* target_out_path, uid_t* uid, gid_t* gid,
                    mode_t* mode, uint64_t* capabilities) {
  // Only root has the necessary permissions to be able to apply fs_config.
  if (getuid() != 0) {
    return;
  }
  struct fs_config conf;
  if (get_fs_config(path, dir, target_out_path, &conf)) {
    *uid = conf.uid;
    *gid = conf.gid;
    *mode = conf.mode;
    *capabilities = conf.capabilities;
  }
}
