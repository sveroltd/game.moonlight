/*
 *      Copyright (C) 2015 Anthony Miyaguchi
 *      Copyright (C) 2015 Team XBMC
 *
 *  This Program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2, or (at your option)
 *  any later version.
 *
 *  This Program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with XBMC; see the file COPYING.  If not, see
 *  <http://www.gnu.org/licenses/>.
 *
 */
#pragma once

#include <openssl/x509v3.h>
#include <openssl/pkcs12.h>
#include <string>

namespace MOONLIGHT
{
  class CertKeyPair
  {
  public:
    CertKeyPair();
    virtual ~CertKeyPair();
    bool generate();
    void save(std::string certFile, std::string p12File, std::string keyPairFile);
  
  private:
    bool make_cert(int bits, int serial, int years);
    bool add_extension(int nid, char* value);
    X509*     m_x509;
    EVP_PKEY* m_pkey;
    PKCS12*   m_p12;
  };
}