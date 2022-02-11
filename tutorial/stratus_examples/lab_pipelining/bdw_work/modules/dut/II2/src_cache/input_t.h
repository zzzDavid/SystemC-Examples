///////////////////////////////////////////////////////////////////////////////
//
// Copyright (c) 2017 Cadence Design Systems, Inc. All rights reserved worldwide.
//
// The code contained herein is the proprietary and confidential information
// of Cadence or its licensors, and is supplied subject to a previously
// executed license and maintenance agreement between Cadence and customer.
// This code is intended for use with Cadence high-level synthesis tools and
// may not be used with other high-level synthesis tools. Permission is only
// granted to distribute the code as indicated. Cadence grants permission for
// customer to distribute a copy of this code to any partner to aid in designing
// or verifying the customer's intellectual property, as long as such
// distribution includes a restriction of no additional distributions from the
// partner, unless the partner receives permission directly from Cadence.
//
// ALL CODE FURNISHED BY CADENCE IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY
// KIND, AND CADENCE SPECIFICALLY DISCLAIMS ANY WARRANTY OF NONINFRINGEMENT,
// FITNESS FOR A PARTICULAR PURPOSE OR MERCHANTABILITY. CADENCE SHALL NOT BE
// LIABLE FOR ANY COSTS OF PROCUREMENT OF SUBSTITUTES, LOSS OF PROFITS,
// INTERRUPTION OF BUSINESS, OR FOR ANY OTHER SPECIAL, CONSEQUENTIAL OR
// INCIDENTAL DAMAGES, HOWEVER CAUSED, WHETHER FOR BREACH OF WARRANTY,
// CONTRACT, TORT, NEGLIGENCE, STRICT LIABILITY OR OTHERWISE.
//
////////////////////////////////////////////////////////////////////////////////

#ifndef input_t_H
#define input_t_H

struct input_t
{
    sc_uint<8> a;
    sc_uint<8> b;
    sc_uint<8> c;
    sc_uint<8> d;
    sc_uint<8> e;
    sc_uint<8> f;
    sc_uint<8> g;
    sc_uint<8> h;
    input_t() {}

    input_t( const input_t & obj )
    {
        copy( obj );
    }
    input_t( sc_uint<8> in_a, sc_uint<8> in_b, sc_uint<8> in_c, sc_uint<8> in_d, sc_uint<8> in_e, sc_uint<8> in_f, sc_uint<8> in_g, sc_uint<8> in_h )
        : a( in_a )
        , b( in_b )
        , c( in_c )
        , d( in_d )
        , e( in_e )
        , f( in_f )
        , g( in_g )
        , h( in_h )
    {
    }

    input_t & operator=( const input_t & obj )
    {
        copy( obj );
        return *this;
    }
    bool operator==( const input_t & obj )
    {
        return (
                   ( a == obj.a )
                   && ( b == obj.b )
                   && ( c == obj.c )
                   && ( d == obj.d )
                   && ( e == obj.e )
                   && ( f == obj.f )
                   && ( g == obj.g )
                   && ( h == obj.h )
               );
    }
    void copy( const input_t & obj )
    {
        a = obj.a;
        b = obj.b;
        c = obj.c;
        d = obj.d;
        e = obj.e;
        f = obj.f;
        g = obj.g;
        h = obj.h;
    }
};
inline void sc_trace( sc_trace_file * tf, const input_t & obj, const std::string & n )
{
    sc_trace( tf, obj.a, n + ".a" );
    sc_trace( tf, obj.b, n + ".b" );
    sc_trace( tf, obj.c, n + ".c" );
    sc_trace( tf, obj.d, n + ".d" );
    sc_trace( tf, obj.e, n + ".e" );
    sc_trace( tf, obj.f, n + ".f" );
    sc_trace( tf, obj.g, n + ".g" );
    sc_trace( tf, obj.h, n + ".h" );
};
inline ostream & operator << ( ostream & os, const input_t  obj )
{
    os
            << " " << obj.a
            << " " << obj.b
            << " " << obj.c
            << " " << obj.d
            << " " << obj.e
            << " " << obj.f
            << " " << obj.g
            << " " << obj.h
            ;
    return os;
};
inline istream & operator >> ( istream & is, input_t & obj )
{
    bool eof = !is.good();

    is >> std::ws;
    eof = is.eof();
    if( !eof )
    {
        is >> obj.a;
    }

    is >> std::ws;
    eof = is.eof();
    if( !eof )
    {
        is >> obj.b;
    }

    is >> std::ws;
    eof = is.eof();
    if( !eof )
    {
        is >> obj.c;
    }

    is >> std::ws;
    eof = is.eof();
    if( !eof )
    {
        is >> obj.d;
    }

    is >> std::ws;
    eof = is.eof();
    if( !eof )
    {
        is >> obj.e;
    }

    is >> std::ws;
    eof = is.eof();
    if( !eof )
    {
        is >> obj.f;
    }

    is >> std::ws;
    eof = is.eof();
    if( !eof )
    {
        is >> obj.g;
    }

    is >> std::ws;
    eof = is.eof();
    if( !eof )
    {
        is >> obj.h;
    }
    return is;
}
#endif
