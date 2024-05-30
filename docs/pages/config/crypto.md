---
title: Encryption
keywords:
tags:
sidebar: mydoc_sidebar
permalink: crypto.html
---

All data files and transaction logs are encrypted before writing to disk. There is support for encrypting network traffic using SSL (client-server as well as replication.) Encryption support is for data at-rest only i.e. it protects systems from attacker with access to physical media. Encryption does not protect against attacker with access to system or process memory. Mechanics for at-rest encryption is similar to Berkeley DB: AES-128 and 16-byte initialization vector, with the following changes:

1. The encrypted files are endian-agnostic

2. Comdb2 uses OpenSSL AES CBC for encryption routines

3. The encrypted data is checksummed using crc32c and the password is used as an HMAC key, providing authenticity of the checksummed data

4. Initialization vector is generated using RAND_bytes()

5. Comdb2's Berkeley DB environment is always opened with DB_PRIVATE flag

Encryption can only be enabled at database creation time. To modify encryption settings (change password, enable or disable encryption) requires a dump and load of existing data.

To enable encryption at database creation time, add the following to the lrl file:

crypto /path/to/password #where the path points to a password file that contains a minimum 14 character password.  

Then pass the lrl file to comdb2 --create, as follows:

comdb2 --create --lrl /home/me/enc.lrl

There are no key management facilities at this point and it is up to the admin to properly secure the password file.
