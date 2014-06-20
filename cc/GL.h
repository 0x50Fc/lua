//
//  GL.h
//  glelement
//
//  Created by zhang hailong on 14-6-19.
//  Copyright (c) 2014年 hailong.org. All rights reserved.
//

#ifndef __glelement__GL__
#define __glelement__GL__

#include <iostream>
#include <math.h>

#ifdef __MACOS__

#ifdef __MACOSX__

#include <OpenGL/OpenGL.h>
#include <OpenGL/gl.h>
#include <OpenGL/glext.h>

#else
#include <OpenGLES/ES1/gl.h>
#include <OpenGLES/ES1/glext.h>
#include <OpenGLES/ES2/gl.h>
#include <OpenGLES/ES2/glext.h>
#endif

#elif defined __ANDROID__

#include <GLES2/gl2.h>
#include <GLES2/gl2ext.h>

#define GL_BGRA	GL_BGRA_EXT

#endif

namespace cc {
    
    typedef union _GLMatrix2{
        struct
        {
            GLfloat m00, m01;
            GLfloat m10, m11;
        };
        GLfloat m[4];
    }GLMatrix2;
    
    typedef union _GLMatrix3{
        struct
        {
            GLfloat m00, m01, m02;
            GLfloat m10, m11, m12;
            GLfloat m20, m21, m22;
        };
        GLfloat m[9];
    }GLMatrix3;
    
    extern const GLMatrix3 GLMatrix3Identity;
    
    typedef union _GLMatrix4
    {
        struct
        {
            GLfloat m00, m01, m02, m03;
            GLfloat m10, m11, m12, m13;
            GLfloat m20, m21, m22, m23;
            GLfloat m30, m31, m32, m33;
        };
        GLfloat m[16];
    } GLMatrix4;
    
    typedef union _GLVector2
    {
        struct { GLfloat x, y; };
        struct { GLfloat s, t; };
        struct { GLfloat width, height; };
        GLfloat v[2];
    }GLVector2;
    
    typedef union _GLVector3
    {
        struct { GLfloat x, y, z; };
        struct { GLfloat r, g, b; };
        struct { GLfloat s, t, p; };
        GLfloat v[3];
    }GLVector3;
    
    typedef union _GLVector4
    {
        struct { GLfloat x, y, z, w; };
        struct { GLfloat r, g, b, a; };
        struct { GLfloat s, t, p, q; };
        struct {
            GLVector2 origin;
            GLVector2 size;
        };
        
        GLfloat v[4];
        
    } GLVector4 ;

    typedef GLVector4 GLColor3d;
    
    int GLColor3dToIntValue(GLColor3d color);
    
    GLColor3d GLColor3dFromIntValue(int value);
    
    GLColor3d GLColor3dFromString(const char * value);
    
    extern const GLMatrix4 GLMatrix4Identity;
    
    static __inline__ GLfloat GLVector3Length(GLVector3 Vector);
    static __inline__ GLfloat GLVector3Length2(GLVector3 Vector);
    static __inline__ GLfloat GLVector4Length(GLVector4 Vector);
    static __inline__ GLfloat GLVector4Length2(GLVector4 Vector);
    static __inline__ GLVector3 GLVector3Normalize(GLVector3 Vector);
    static __inline__ GLVector3 GLVector3Make(GLfloat x, GLfloat y, GLfloat z);
    
    extern GLMatrix3 cid_Matrix3InvertTranspose(GLMatrix3 Matrix);
    
    static __inline__ GLMatrix3 GLMatrix3Transpose(GLMatrix3 Matrix);
    
    static __inline__ GLMatrix3 GLMatrix4ToMatrix3(GLMatrix4 Matrix4);
    
    static __inline__ GLVector3 GLVector3MultiplyScalar(GLVector3 Vector, GLfloat value);
    static __inline__ GLVector3 GLVector3Add(GLVector3 VectorLeft, GLVector3 VectorRight);
    static __inline__ GLVector3 GLVector3Sub(GLVector3 VectorLeft, GLVector3 VectorRight);
    
    static __inline__ GLVector3 GLVector3Anim(GLVector3 from,GLVector3 to,GLfloat value);
    
    static __inline__ GLVector3 GLVector3AnimOffset(GLVector3 from,GLVector3 to,GLfloat value);
    
    static __inline__ GLVector3 GLVector3Project(GLVector3 a, GLVector3 b,GLVector3 c);
    
    static __inline__ GLfloat GLVector3Project_scalar(GLVector3 a, GLVector3 b,GLVector3 c);
    
    static __inline__ GLfloat GLVector3Dot(GLVector3 a, GLVector3 b);
    
    static __inline__ GLMatrix3 GLMatrix3Multiply(GLMatrix3 MatrixLeft, GLMatrix3 MatrixRight);
    
    static __inline__ GLMatrix3 GLMatrix3MultiplyAnim(GLMatrix3 MatrixLeft, GLMatrix3 MatrixRight,GLfloat value);
    
    static __inline__ GLMatrix3 GLMatrix3Multiply(GLMatrix3 MatrixLeft, GLMatrix3 MatrixRight);
    
    static __inline__ GLMatrix3 GLMatrix3MultiplyScalar(GLMatrix3 MatrixLeft, GLfloat value);
    
    static __inline__ GLMatrix3 GLMatrix3Add(GLMatrix3 MatrixLeft, GLMatrix3 MatrixRight);
    static __inline__ GLMatrix3 GLMatrix3Sub(GLMatrix3 MatrixLeft, GLMatrix3 MatrixRight);
    
    static __inline__ GLMatrix3 GLMatrix3MakeProject(GLVector3 v3);
    
    static __inline__ GLMatrix3 GLMatrix3MakeScale(GLfloat sx, GLfloat sy, GLfloat sz);
    static __inline__ GLMatrix3 GLMatrix3MakeRotation(GLfloat radians, GLfloat x, GLfloat y, GLfloat z);
    
    static __inline__ GLMatrix3 GLMatrix3MakeRotationX(GLfloat radians);
    static __inline__ GLMatrix3 GLMatrix3MakeRotationY(GLfloat radians);
    static __inline__ GLMatrix3 GLMatrix3MakeRotationZ(GLfloat radians);
    
    static __inline__ GLMatrix3 GLMatrix3Scale(GLMatrix3 Matrix, GLfloat sx, GLfloat sy, GLfloat sz);
    static __inline__ GLMatrix3 GLMatrix3Rotate(GLMatrix3 Matrix, GLfloat radians, GLfloat x, GLfloat y, GLfloat z);
    static __inline__ GLMatrix3 GLMatrix3RotateX(GLMatrix3 Matrix, GLfloat radians);
    static __inline__ GLMatrix3 GLMatrix3RotateY(GLMatrix3 Matrix, GLfloat radians);
    static __inline__ GLMatrix3 GLMatrix3RotateZ(GLMatrix3 Matrix, GLfloat radians);
    
    
    static __inline__ GLMatrix4 GLMatrix4Multiply(GLMatrix4 MatrixLeft, GLMatrix4 MatrixRight);
    
    static __inline__ GLVector3 GLMatrix4MultiplyVector3(GLMatrix4 MatrixLeft, GLVector3 VectorRight,GLfloat v3);
    
    static __inline__ GLVector4 GLMatrix4MultiplyVector4(GLMatrix4 MatrixLeft, GLVector4 VectorRight);
    
    static __inline__ GLVector3 GLMatrix4MultiplyVector3Project(GLMatrix4 MatrixLeft, GLVector3 VectorRight);
    
    static __inline__ GLMatrix4 GLMatrix4MakeProject(GLVector3 v3);
    
    static __inline__ GLMatrix4 GLMatrix4MakeTranslation(GLfloat tx, GLfloat ty, GLfloat tz);
    static __inline__ GLMatrix4 GLMatrix4MakeScale(GLfloat sx, GLfloat sy, GLfloat sz);
    static __inline__ GLMatrix4 GLMatrix4MakeRotation(GLfloat radians, GLfloat x, GLfloat y, GLfloat z);
    
    static __inline__ GLMatrix4 GLMatrix4MakeRotationX(GLfloat radians);
    static __inline__ GLMatrix4 GLMatrix4MakeRotationY(GLfloat radians);
    static __inline__ GLMatrix4 GLMatrix4MakeRotationZ(GLfloat radians);
    
    static __inline__ GLMatrix4 GLMatrix4Translate(GLMatrix4 Matrix, GLfloat tx, GLfloat ty, GLfloat tz);
    static __inline__ GLMatrix4 GLMatrix4Scale(GLMatrix4 Matrix, GLfloat sx, GLfloat sy, GLfloat sz);
    static __inline__ GLMatrix4 GLMatrix4Rotate(GLMatrix4 Matrix, GLfloat radians, GLfloat x, GLfloat y, GLfloat z);
    static __inline__ GLMatrix4 GLMatrix4RotateX(GLMatrix4 Matrix, GLfloat radians);
    static __inline__ GLMatrix4 GLMatrix4RotateY(GLMatrix4 Matrix, GLfloat radians);
    static __inline__ GLMatrix4 GLMatrix4RotateZ(GLMatrix4 Matrix, GLfloat radians);
    
    static __inline__ GLMatrix4 GLMatrix4MultiplyScalar(GLMatrix4 Matrix4 ,GLfloat value);
    static __inline__ GLMatrix4 GLMatrix4Add(GLMatrix4 MatrixLeft ,GLMatrix4 MatrixRight);
    static __inline__ GLMatrix4 GLMatrix4Sub(GLMatrix4 MatrixLeft ,GLMatrix4 MatrixRight);
    
    static __inline__ GLMatrix3 GLQuatToMatrix3(GLVector4 quat) ;
    
    static __inline__ GLVector4 GLMatrix3ToQuat(GLMatrix3 Matrix3) ;
    
    static __inline__ GLMatrix4 GLMatrix3ToMatrix4(GLMatrix3 Matrix);
    
    static __inline__ GLMatrix4 GLMatrix4MultiplyAnim(GLMatrix4 MatrixLeft, GLMatrix4 MatrixRight,GLfloat value);
    
    static __inline__ GLVector4 GLQuatToAxis(GLVector4 q);
    
    static __inline__ GLVector4 GLAxisToQuat(GLVector4 a);
    
    static __inline__ GLfloat GLVector3Length(GLVector3 Vector)
    {
        return sqrt(Vector.v[0] * Vector.v[0] + Vector.v[1] * Vector.v[1] + Vector.v[2] * Vector.v[2]);
    }
    
    static __inline__ GLfloat GLVector3Length2(GLVector3 Vector)
    {
        return Vector.v[0] * Vector.v[0] + Vector.v[1] * Vector.v[1] + Vector.v[2] * Vector.v[2];
    }
    
    static __inline__ GLfloat GLVector4Length(GLVector4 Vector)
    {
        return sqrt(Vector.v[0] * Vector.v[0] + Vector.v[1] * Vector.v[1] + Vector.v[2] * Vector.v[2] + Vector.v[3] * Vector.v[3]);
    }
    
    static __inline__ GLfloat GLVector4Length2(GLVector4 Vector)
    {
        return Vector.v[0] * Vector.v[0] + Vector.v[1] * Vector.v[1] + Vector.v[2] * Vector.v[2] + Vector.v[3] * Vector.v[3];
    }
    
    static __inline__ GLVector3 GLVector3Normalize(GLVector3 Vector)
    {
        GLfloat scale = 1.0f / GLVector3Length(Vector);
        GLVector3 v = { Vector.v[0] * scale, Vector.v[1] * scale, Vector.v[2] * scale };
        return v;
    }
    
    static __inline__ GLVector3 GLVector3Make(GLfloat x, GLfloat y, GLfloat z)
    {
        GLVector3 v = { x, y, z };
        return v;
    }
    
    static __inline__ GLVector3 GLVector3MultiplyScalar(GLVector3 Vector, GLfloat value)
    {
        GLVector3 v = { Vector.v[0] * value,
            Vector.v[1] * value,
            Vector.v[2] * value };
        return v;
    }
    
    static __inline__ GLVector3 GLVector3Add(GLVector3 VectorLeft, GLVector3 VectorRight){
        GLVector3 v = { VectorLeft.v[0] + VectorRight.v[0],
            VectorLeft.v[1] + VectorRight.v[1],
            VectorLeft.v[2] + VectorRight.v[2] };
        return v;
    }
    
    static __inline__ GLVector3 GLVector3Sub(GLVector3 VectorLeft, GLVector3 VectorRight){
        GLVector3 v = { VectorLeft.v[0] - VectorRight.v[0],
            VectorLeft.v[1] - VectorRight.v[1],
            VectorLeft.v[2] - VectorRight.v[2] };
        return v;
    }
    
    static __inline__ GLVector3 GLVector3Anim(GLVector3 from,GLVector3 to,GLfloat value){
        GLVector3 v = { from.x + (to.x - from.x) * value,
            from.y + (to.y - from.y) * value,
            from.z + (to.z - from.z) * value };
        return v;
    }
    
    static __inline__ GLVector3 GLVector3AnimOffset(GLVector3 from,GLVector3 to,GLfloat value){
        GLVector3 v = { (to.x - from.x) * value,
            (to.y - from.y) * value,
            (to.z - from.z) * value };
        return v;
    }
    
    static __inline__ GLfloat GLVector3Dot(GLVector3 a, GLVector3 b){
        return a.x * b.x + a.y * b.y + a.z * b.z;
    }
    
    static __inline__ GLfloat GLVector3Project_scalar(GLVector3 a, GLVector3 b,GLVector3 c){
        GLVector3 ab = GLVector3Sub(b, a);
        GLVector3 ac = GLVector3Sub(c, a);
        return GLVector3Dot(ab,ac) / GLVector3Dot(ab,ab);
    }
    
    static __inline__ GLVector3 GLVector3Project(GLVector3 a, GLVector3 b,GLVector3 c){
        GLVector3 ab = GLVector3Sub(b, a);
        GLVector3 ac = GLVector3Sub(c, a);
        GLVector3 v = GLVector3Add(a, GLVector3MultiplyScalar(ab, GLVector3Dot(ab,ac) / GLVector3Dot(ab,ab)) );
        return v;
    }
    
    static __inline__ GLMatrix3 GLMatrix4ToMatrix3(GLMatrix4 Matrix4){
        GLMatrix3 m3 = {
            Matrix4.m00,Matrix4.m01,Matrix4.m02,
            Matrix4.m10,Matrix4.m11,Matrix4.m12,
            Matrix4.m20,Matrix4.m21,Matrix4.m22,
        };
        
        return m3;
    }
    
    static __inline__ GLMatrix4 GLMatrix4Multiply(GLMatrix4 MatrixLeft, GLMatrix4 MatrixRight)
    {
        GLMatrix4 m;
        
        m.m[0]  = MatrixLeft.m[0] * MatrixRight.m[0]  + MatrixLeft.m[4] * MatrixRight.m[1]  + MatrixLeft.m[8] * MatrixRight.m[2]   + MatrixLeft.m[12] * MatrixRight.m[3];
        m.m[4]  = MatrixLeft.m[0] * MatrixRight.m[4]  + MatrixLeft.m[4] * MatrixRight.m[5]  + MatrixLeft.m[8] * MatrixRight.m[6]   + MatrixLeft.m[12] * MatrixRight.m[7];
        m.m[8]  = MatrixLeft.m[0] * MatrixRight.m[8]  + MatrixLeft.m[4] * MatrixRight.m[9]  + MatrixLeft.m[8] * MatrixRight.m[10]  + MatrixLeft.m[12] * MatrixRight.m[11];
        m.m[12] = MatrixLeft.m[0] * MatrixRight.m[12] + MatrixLeft.m[4] * MatrixRight.m[13] + MatrixLeft.m[8] * MatrixRight.m[14]  + MatrixLeft.m[12] * MatrixRight.m[15];
        
        m.m[1]  = MatrixLeft.m[1] * MatrixRight.m[0]  + MatrixLeft.m[5] * MatrixRight.m[1]  + MatrixLeft.m[9] * MatrixRight.m[2]   + MatrixLeft.m[13] * MatrixRight.m[3];
        m.m[5]  = MatrixLeft.m[1] * MatrixRight.m[4]  + MatrixLeft.m[5] * MatrixRight.m[5]  + MatrixLeft.m[9] * MatrixRight.m[6]   + MatrixLeft.m[13] * MatrixRight.m[7];
        m.m[9]  = MatrixLeft.m[1] * MatrixRight.m[8]  + MatrixLeft.m[5] * MatrixRight.m[9]  + MatrixLeft.m[9] * MatrixRight.m[10]  + MatrixLeft.m[13] * MatrixRight.m[11];
        m.m[13] = MatrixLeft.m[1] * MatrixRight.m[12] + MatrixLeft.m[5] * MatrixRight.m[13] + MatrixLeft.m[9] * MatrixRight.m[14]  + MatrixLeft.m[13] * MatrixRight.m[15];
        
        m.m[2]  = MatrixLeft.m[2] * MatrixRight.m[0]  + MatrixLeft.m[6] * MatrixRight.m[1]  + MatrixLeft.m[10] * MatrixRight.m[2]  + MatrixLeft.m[14] * MatrixRight.m[3];
        m.m[6]  = MatrixLeft.m[2] * MatrixRight.m[4]  + MatrixLeft.m[6] * MatrixRight.m[5]  + MatrixLeft.m[10] * MatrixRight.m[6]  + MatrixLeft.m[14] * MatrixRight.m[7];
        m.m[10] = MatrixLeft.m[2] * MatrixRight.m[8]  + MatrixLeft.m[6] * MatrixRight.m[9]  + MatrixLeft.m[10] * MatrixRight.m[10] + MatrixLeft.m[14] * MatrixRight.m[11];
        m.m[14] = MatrixLeft.m[2] * MatrixRight.m[12] + MatrixLeft.m[6] * MatrixRight.m[13] + MatrixLeft.m[10] * MatrixRight.m[14] + MatrixLeft.m[14] * MatrixRight.m[15];
        
        m.m[3]  = MatrixLeft.m[3] * MatrixRight.m[0]  + MatrixLeft.m[7] * MatrixRight.m[1]  + MatrixLeft.m[11] * MatrixRight.m[2]  + MatrixLeft.m[15] * MatrixRight.m[3];
        m.m[7]  = MatrixLeft.m[3] * MatrixRight.m[4]  + MatrixLeft.m[7] * MatrixRight.m[5]  + MatrixLeft.m[11] * MatrixRight.m[6]  + MatrixLeft.m[15] * MatrixRight.m[7];
        m.m[11] = MatrixLeft.m[3] * MatrixRight.m[8]  + MatrixLeft.m[7] * MatrixRight.m[9]  + MatrixLeft.m[11] * MatrixRight.m[10] + MatrixLeft.m[15] * MatrixRight.m[11];
        m.m[15] = MatrixLeft.m[3] * MatrixRight.m[12] + MatrixLeft.m[7] * MatrixRight.m[13] + MatrixLeft.m[11] * MatrixRight.m[14] + MatrixLeft.m[15] * MatrixRight.m[15];
        
        return m;
    }
    
    static __inline__ GLVector3 GLMatrix4MultiplyVector3(GLMatrix4 MatrixLeft, GLVector3 VectorRight ,GLfloat v3)
    {
        GLVector3 v = { MatrixLeft.m[0] * VectorRight.v[0] + MatrixLeft.m[4] * VectorRight.v[1] + MatrixLeft.m[8] * VectorRight.v[2] + MatrixLeft.m[12] * v3,
            MatrixLeft.m[1] * VectorRight.v[0] + MatrixLeft.m[5] * VectorRight.v[1] + MatrixLeft.m[9] * VectorRight.v[2] + MatrixLeft.m[13] * v3,
            MatrixLeft.m[2] * VectorRight.v[0] + MatrixLeft.m[6] * VectorRight.v[1] + MatrixLeft.m[10] * VectorRight.v[2] + MatrixLeft.m[14] * v3 };
        return v;
    }
    
    static __inline__ GLVector4 GLMatrix4MultiplyVector4(GLMatrix4 MatrixLeft, GLVector4 VectorRight)
    {
        GLVector4 v = { MatrixLeft.m[0] * VectorRight.v[0] + MatrixLeft.m[4] * VectorRight.v[1] + MatrixLeft.m[8] * VectorRight.v[2] + MatrixLeft.m[12] * VectorRight.v[3],
            MatrixLeft.m[1] * VectorRight.v[0] + MatrixLeft.m[5] * VectorRight.v[1] + MatrixLeft.m[9] * VectorRight.v[2] + MatrixLeft.m[13] * VectorRight.v[3],
            MatrixLeft.m[2] * VectorRight.v[0] + MatrixLeft.m[6] * VectorRight.v[1] + MatrixLeft.m[10] * VectorRight.v[2] + MatrixLeft.m[14] * VectorRight.v[3],
            MatrixLeft.m[3] * VectorRight.v[0] + MatrixLeft.m[7] * VectorRight.v[1] + MatrixLeft.m[11] * VectorRight.v[2] + MatrixLeft.m[15] * VectorRight.v[3] };
        return v;
    }
    
    static __inline__ GLVector3 GLMatrix4MultiplyVector3Project(GLMatrix4 MatrixLeft, GLVector3 VectorRight)
    {
        GLVector4 v = {VectorRight.v[0],VectorRight.v[1],VectorRight.v[2],1.0f};
        GLVector4 v4 = GLMatrix4MultiplyVector4(MatrixLeft, v);
        GLVector3 v3 = {v4.v[0], v4.v[1], v4.v[2]};
        return GLVector3MultiplyScalar(v3, 1.0f / v4.v[3]);
    }
    
    static __inline__ GLMatrix4 GLMatrix4MakeTranslation(GLfloat tx, GLfloat ty, GLfloat tz)
    {
        GLMatrix4 m = GLMatrix4Identity;
        m.m[12] = tx;
        m.m[13] = ty;
        m.m[14] = tz;
        return m;
    }
    
    static __inline__ GLMatrix4 GLMatrix4MakeScale(GLfloat sx, GLfloat sy, GLfloat sz)
    {
        GLMatrix4 m = GLMatrix4Identity;
        m.m[0] = sx;
        m.m[5] = sy;
        m.m[10] = sz;
        return m;
    }
    
    static __inline__ GLMatrix4 GLMatrix4MakeRotation(GLfloat radians, GLfloat x, GLfloat y, GLfloat z)
    {
        GLVector3 v = GLVector3Normalize(GLVector3Make(x, y, z));
        GLfloat cos = cosf(radians);
        GLfloat cosp = 1.0f - cos;
        GLfloat sin = sinf(radians);
        
        GLMatrix4 m = { cos + cosp * v.v[0] * v.v[0],
            cosp * v.v[0] * v.v[1] + v.v[2] * sin,
            cosp * v.v[0] * v.v[2] - v.v[1] * sin,
            0.0f,
            cosp * v.v[0] * v.v[1] - v.v[2] * sin,
            cos + cosp * v.v[1] * v.v[1],
            cosp * v.v[1] * v.v[2] + v.v[0] * sin,
            0.0f,
            cosp * v.v[0] * v.v[2] + v.v[1] * sin,
            cosp * v.v[1] * v.v[2] - v.v[0] * sin,
            cos + cosp * v.v[2] * v.v[2],
            0.0f,
            0.0f,
            0.0f,
            0.0f,
            1.0f };
        
        return m;
    }
    
    static __inline__ GLMatrix4 GLMatrix4MakeRotationX(GLfloat radians)
    {
        GLfloat cos = cosf(radians);
        GLfloat sin = sinf(radians);
        
        GLMatrix4 m = { 1.0f, 0.0f, 0.0f, 0.0f,
            0.0f, cos, sin, 0.0f,
            0.0f, -sin, cos, 0.0f,
            0.0f, 0.0f, 0.0f, 1.0f };
        
        return m;
    }
    
    static __inline__ GLMatrix4 GLMatrix4MakeRotationY(GLfloat radians)
    {
        GLfloat cos = cosf(radians);
        GLfloat sin = sinf(radians);
        
        GLMatrix4 m = { cos, 0.0f, -sin, 0.0f,
            0.0f, 1.0f, 0.0f, 0.0f,
            sin, 0.0f, cos, 0.0f,
            0.0f, 0.0f, 0.0f, 1.0f };
        
        return m;
    }
    
    static __inline__ GLMatrix4 GLMatrix4MakeRotationZ(GLfloat radians)
    {
        GLfloat cos = cosf(radians);
        GLfloat sin = sinf(radians);
        
        GLMatrix4 m = { cos, sin, 0.0f, 0.0f,
            -sin, cos, 0.0f, 0.0f,
            0.0f, 0.0f, 1.0f, 0.0f,
            0.0f, 0.0f, 0.0f, 1.0f };
        
        return m;
    }
    
    static __inline__ GLMatrix4 GLMatrix4Translate(GLMatrix4 Matrix, GLfloat tx, GLfloat ty, GLfloat tz)
    {
        GLMatrix4 m = { Matrix.m[0], Matrix.m[1], Matrix.m[2], Matrix.m[3],
            Matrix.m[4], Matrix.m[5], Matrix.m[6], Matrix.m[7],
            Matrix.m[8], Matrix.m[9], Matrix.m[10], Matrix.m[11],
            Matrix.m[0] * tx + Matrix.m[4] * ty + Matrix.m[8] * tz + Matrix.m[12],
            Matrix.m[1] * tx + Matrix.m[5] * ty + Matrix.m[9] * tz + Matrix.m[13],
            Matrix.m[2] * tx + Matrix.m[6] * ty + Matrix.m[10] * tz + Matrix.m[14],
            Matrix.m[15] };
        return m;
    }
    
    static __inline__ GLMatrix4 GLMatrix4Scale(GLMatrix4 Matrix, GLfloat sx, GLfloat sy, GLfloat sz)
    {
        
        GLMatrix4 m = { Matrix.m[0] * sx, Matrix.m[1] * sx, Matrix.m[2] * sx, Matrix.m[3] * sx,
            Matrix.m[4] * sy, Matrix.m[5] * sy, Matrix.m[6] * sy, Matrix.m[7] * sy,
            Matrix.m[8] * sz, Matrix.m[9] * sz, Matrix.m[10] * sz, Matrix.m[11] * sz,
            Matrix.m[12], Matrix.m[13], Matrix.m[14], Matrix.m[15] };
        return m;
    }
    
    static __inline__ GLMatrix4 GLMatrix4Rotate(GLMatrix4 Matrix, GLfloat radians, GLfloat x, GLfloat y, GLfloat z)
    {
        GLMatrix4 rm = GLMatrix4MakeRotation(radians, x, y, z);
        return GLMatrix4Multiply(Matrix, rm);
    }
    
    static __inline__ GLMatrix4 GLMatrix4RotateX(GLMatrix4 Matrix, GLfloat radians)
    {
        GLMatrix4 rm = GLMatrix4MakeRotationX(radians);
        return GLMatrix4Multiply(Matrix, rm);
    }
    
    static __inline__ GLMatrix4 GLMatrix4RotateY(GLMatrix4 Matrix, GLfloat radians)
    {
        GLMatrix4 rm = GLMatrix4MakeRotationY(radians);
        return GLMatrix4Multiply(Matrix, rm);
    }
    
    static __inline__ GLMatrix4 GLMatrix4RotateZ(GLMatrix4 Matrix, GLfloat radians)
    {
        GLMatrix4 rm = GLMatrix4MakeRotationZ(radians);
        return GLMatrix4Multiply(Matrix, rm);
    }
    
    static __inline__ GLMatrix4 GLMatrix4MultiplyScalar(GLMatrix4 Matrix4 ,GLfloat value){
        GLMatrix4 m4 = {
            Matrix4.m00 * value,Matrix4.m01 * value,Matrix4.m02 * value,Matrix4.m03 * value,
            Matrix4.m10 * value,Matrix4.m11 * value,Matrix4.m12 * value,Matrix4.m13 * value,
            Matrix4.m20 * value,Matrix4.m21 * value,Matrix4.m22 * value,Matrix4.m23 * value,
            Matrix4.m30 * value,Matrix4.m31 * value,Matrix4.m32 * value,Matrix4.m33 * value,
        };
        return m4;
    }
    
    static __inline__ GLMatrix4 GLMatrix4Add(GLMatrix4 MatrixLeft ,GLMatrix4 MatrixRight){
        GLMatrix4 m4 = {
            MatrixLeft.m00 + MatrixRight.m00,MatrixLeft.m01 + MatrixRight.m01,MatrixLeft.m02 + MatrixRight.m02,MatrixLeft.m03 + MatrixRight.m03,
            MatrixLeft.m10 + MatrixRight.m10,MatrixLeft.m11 + MatrixRight.m11,MatrixLeft.m12 + MatrixRight.m12,MatrixLeft.m13 + MatrixRight.m13,
            MatrixLeft.m20 + MatrixRight.m20,MatrixLeft.m21 + MatrixRight.m21,MatrixLeft.m22 + MatrixRight.m22,MatrixLeft.m23 + MatrixRight.m23,
            MatrixLeft.m30 + MatrixRight.m30,MatrixLeft.m31 + MatrixRight.m31,MatrixLeft.m32 + MatrixRight.m32,MatrixLeft.m33 + MatrixRight.m33,
        };
        return m4;
    }
    
    static __inline__ GLMatrix4 GLMatrix4Sub(GLMatrix4 MatrixLeft ,GLMatrix4 MatrixRight){
        GLMatrix4 m4 = {
            MatrixLeft.m00 - MatrixRight.m00,MatrixLeft.m01 - MatrixRight.m01,MatrixLeft.m02 - MatrixRight.m02,MatrixLeft.m03 - MatrixRight.m03,
            MatrixLeft.m10 - MatrixRight.m10,MatrixLeft.m11 - MatrixRight.m11,MatrixLeft.m12 - MatrixRight.m12,MatrixLeft.m13 - MatrixRight.m13,
            MatrixLeft.m20 - MatrixRight.m20,MatrixLeft.m21 - MatrixRight.m21,MatrixLeft.m22 - MatrixRight.m22,MatrixLeft.m23 - MatrixRight.m23,
            MatrixLeft.m30 - MatrixRight.m30,MatrixLeft.m31 - MatrixRight.m31,MatrixLeft.m32 - MatrixRight.m32,MatrixLeft.m33 - MatrixRight.m33,
        };
        return m4;
    }
    
    
    static __inline__ GLMatrix3 GLMatrix3Multiply(GLMatrix3 MatrixLeft, GLMatrix3 MatrixRight){
        GLMatrix3 m;
        
        m.m[0] = MatrixLeft.m[0] * MatrixRight.m[0] + MatrixLeft.m[3] * MatrixRight.m[1] + MatrixLeft.m[6] * MatrixRight.m[2];
        m.m[3] = MatrixLeft.m[0] * MatrixRight.m[3] + MatrixLeft.m[3] * MatrixRight.m[4] + MatrixLeft.m[6] * MatrixRight.m[5];
        m.m[6] = MatrixLeft.m[0] * MatrixRight.m[6] + MatrixLeft.m[3] * MatrixRight.m[7] + MatrixLeft.m[6] * MatrixRight.m[8];
        
        m.m[1] = MatrixLeft.m[1] * MatrixRight.m[0] + MatrixLeft.m[4] * MatrixRight.m[1] + MatrixLeft.m[7] * MatrixRight.m[2];
        m.m[4] = MatrixLeft.m[1] * MatrixRight.m[3] + MatrixLeft.m[4] * MatrixRight.m[4] + MatrixLeft.m[7] * MatrixRight.m[5];
        m.m[7] = MatrixLeft.m[1] * MatrixRight.m[6] + MatrixLeft.m[4] * MatrixRight.m[7] + MatrixLeft.m[7] * MatrixRight.m[8];
        
        m.m[2] = MatrixLeft.m[2] * MatrixRight.m[0] + MatrixLeft.m[5] * MatrixRight.m[1] + MatrixLeft.m[8] * MatrixRight.m[2];
        m.m[5] = MatrixLeft.m[2] * MatrixRight.m[3] + MatrixLeft.m[5] * MatrixRight.m[4] + MatrixLeft.m[8] * MatrixRight.m[5];
        m.m[8] = MatrixLeft.m[2] * MatrixRight.m[6] + MatrixLeft.m[5] * MatrixRight.m[7] + MatrixLeft.m[8] * MatrixRight.m[8];
        
        return m;
    }
    
    static __inline__ GLMatrix3 GLMatrix3ranspose(GLMatrix3 Matrix)
    {
        GLMatrix3 m = { Matrix.m[0], Matrix.m[3], Matrix.m[6],
            Matrix.m[1], Matrix.m[4], Matrix.m[7],
            Matrix.m[2], Matrix.m[5], Matrix.m[8] };
        return m;
    }
    
    static __inline__ GLMatrix3 GLMatrix3MultiplyScalar(GLMatrix3 MatrixLeft, GLfloat value){
        GLMatrix3 m3 = {
            MatrixLeft.m00 * value,MatrixLeft.m01 * value,MatrixLeft.m02 * value,
            MatrixLeft.m10 * value,MatrixLeft.m11 * value,MatrixLeft.m12 * value,
            MatrixLeft.m20 * value,MatrixLeft.m21 * value,MatrixLeft.m22 * value
        };
        return m3;
    }
    
    
    static __inline__ GLMatrix3 GLMatrix3Add(GLMatrix3 MatrixLeft, GLMatrix3 MatrixRight)
    {
        GLMatrix3 m;
        
        m.m[0] = MatrixLeft.m[0] + MatrixRight.m[0];
        m.m[1] = MatrixLeft.m[1] + MatrixRight.m[1];
        m.m[2] = MatrixLeft.m[2] + MatrixRight.m[2];
        
        m.m[3] = MatrixLeft.m[3] + MatrixRight.m[3];
        m.m[4] = MatrixLeft.m[4] + MatrixRight.m[4];
        m.m[5] = MatrixLeft.m[5] + MatrixRight.m[5];
        
        m.m[6] = MatrixLeft.m[6] + MatrixRight.m[6];
        m.m[7] = MatrixLeft.m[7] + MatrixRight.m[7];
        m.m[8] = MatrixLeft.m[8] + MatrixRight.m[8];
        
        return m;
    }
    
    static __inline__ GLMatrix3 GLMatrix3Sub(GLMatrix3 MatrixLeft, GLMatrix3 MatrixRight)
    {
        GLMatrix3 m;
        
        m.m[0] = MatrixLeft.m[0] - MatrixRight.m[0];
        m.m[1] = MatrixLeft.m[1] - MatrixRight.m[1];
        m.m[2] = MatrixLeft.m[2] - MatrixRight.m[2];
        
        m.m[3] = MatrixLeft.m[3] - MatrixRight.m[3];
        m.m[4] = MatrixLeft.m[4] - MatrixRight.m[4];
        m.m[5] = MatrixLeft.m[5] - MatrixRight.m[5];
        
        m.m[6] = MatrixLeft.m[6] - MatrixRight.m[6];
        m.m[7] = MatrixLeft.m[7] - MatrixRight.m[7];
        m.m[8] = MatrixLeft.m[8] - MatrixRight.m[8];
        
        return m;
    }
    
    static __inline__ GLVector3 GLMatrix3MultiplyVector3(GLMatrix3 MatrixLeft, GLVector3 VectorRight){
        GLVector3 v = { MatrixLeft.m[0] * VectorRight.v[0] + MatrixLeft.m[3] * VectorRight.v[1] + MatrixLeft.m[6] * VectorRight.v[2],
            MatrixLeft.m[1] * VectorRight.v[0] + MatrixLeft.m[4] * VectorRight.v[1] + MatrixLeft.m[7] * VectorRight.v[2],
            MatrixLeft.m[2] * VectorRight.v[0] + MatrixLeft.m[5] * VectorRight.v[1] + MatrixLeft.m[8] * VectorRight.v[2] };
        return v;
    }
    
    static __inline__ GLMatrix3 GLMatrix3MakeScale(GLfloat sx, GLfloat sy, GLfloat sz){
        GLMatrix3 m = GLMatrix3Identity;
        m.m[0] = sx;
        m.m[4] = sy;
        m.m[8] = sz;
        return m;
    }
    
    static __inline__ GLMatrix3 GLMatrix3MakeRotation(GLfloat radians, GLfloat x, GLfloat y, GLfloat z){
        GLVector3 v3 = {x,y,z};
        GLVector3 v = GLVector3Normalize(v3);
        GLfloat cos = cosf(radians);
        GLfloat cosp = 1.0f - cos;
        GLfloat sin = sinf(radians);
        
        GLMatrix3 m = { cos + cosp * v.v[0] * v.v[0],
            cosp * v.v[0] * v.v[1] + v.v[2] * sin,
            cosp * v.v[0] * v.v[2] - v.v[1] * sin,
            
            cosp * v.v[0] * v.v[1] - v.v[2] * sin,
            cos + cosp * v.v[1] * v.v[1],
            cosp * v.v[1] * v.v[2] + v.v[0] * sin,
            
            cosp * v.v[0] * v.v[2] + v.v[1] * sin,
            cosp * v.v[1] * v.v[2] - v.v[0] * sin,
            cos + cosp * v.v[2] * v.v[2] };
        
        return m;
    }
    
    static __inline__ GLMatrix3 GLMatrix3MakeRotationX(GLfloat radians){
        GLfloat cos = cosf(radians);
        GLfloat sin = sinf(radians);
        
        GLMatrix3 m = { 1.0f, 0.0f, 0.0f,
            0.0f, cos, sin,
            0.0f, -sin, cos };
        
        return m;
    }
    
    static __inline__ GLMatrix3 GLMatrix3MakeRotationY(GLfloat radians){
        GLfloat cos = cosf(radians);
        GLfloat sin = sinf(radians);
        
        GLMatrix3 m = { cos, 0.0f, -sin,
            0.0f, 1.0f, 0.0f,
            sin, 0.0f, cos };
        
        return m;
    }
    
    static __inline__ GLMatrix3 GLMatrix3MakeRotationZ(GLfloat radians){
        GLfloat cos = cosf(radians);
        GLfloat sin = sinf(radians);
        
        GLMatrix3 m = { cos, sin, 0.0f,
            -sin, cos, 0.0f,
            0.0f, 0.0f, 1.0f };
        
        return m;
    }
    
    static __inline__ GLMatrix3 GLMatrix3Scale(GLMatrix3 Matrix, GLfloat sx, GLfloat sy, GLfloat sz){
        GLMatrix3 m = { Matrix.m[0] * sx, Matrix.m[1] * sx, Matrix.m[2] * sx,
            Matrix.m[3] * sy, Matrix.m[4] * sy, Matrix.m[5] * sy,
            Matrix.m[6] * sz, Matrix.m[7] * sz, Matrix.m[8] * sz };
        return m;
    }
    
    static __inline__ GLMatrix3 GLMatrix3Rotate(GLMatrix3 Matrix, GLfloat radians, GLfloat x, GLfloat y, GLfloat z){
        GLMatrix3 rm = GLMatrix3MakeRotation(radians, x, y, z);
        return GLMatrix3Multiply(Matrix, rm);
    }
    
    static __inline__ GLMatrix3 GLMatrix3RotateX(GLMatrix3 Matrix, GLfloat radians){
        GLMatrix3 rm = GLMatrix3MakeRotationX(radians);
        return GLMatrix3Multiply(Matrix, rm);
    }
    
    static __inline__ GLMatrix3 GLMatrix3RotateY(GLMatrix3 Matrix, GLfloat radians){
        GLMatrix3 rm = GLMatrix3MakeRotationY(radians);
        return GLMatrix3Multiply(Matrix, rm);
    }
    
    static __inline__ GLMatrix3 GLMatrix3RotateZ(GLMatrix3 Matrix, GLfloat radians){
        GLMatrix3 rm = GLMatrix3MakeRotationZ(radians);
        return GLMatrix3Multiply(Matrix, rm);
    }
    
    static __inline__ GLMatrix3 GLquato_Matrix3(GLVector4 quat) {
        GLfloat length = GLVector4Length2(quat);
        GLMatrix3 m3 = GLMatrix3Identity;
        if (length == 0.0f)
        {
            m3.m00 = 0.0f; m3.m10 = 0.0f; m3.m20 = 0.0f;
            m3.m01 = 0.0f; m3.m11 = 0.0f; m3.m21 = 0.0f;
            m3.m02 = 0.0f; m3.m12 = 0.0f; m3.m22 = 0.0f;
        }
        else
        {
            GLfloat rlength;
            
            if (length != 1.0)
            {
                rlength = 2.0/length;
            }
            else
            {
                rlength = 2.0;
            }
            
            GLfloat wx, wy, wz, xx, yy, yz, xy, xz, zz, x2, y2, z2;
            
            x2 = rlength* quat.x;
            y2 = rlength* quat.y;
            z2 = rlength* quat.z;
            
            xx = quat.x * x2;
            xy = quat.x * y2;
            xz = quat.x * z2;
            
            yy = quat.y * y2;
            yz = quat.y * z2;
            zz = quat.z * z2;
            
            wx = quat.w * x2;
            wy = quat.w * y2;
            wz = quat.w * z2;
            
            m3.m00 = 1.0 - (yy + zz);
            m3.m10 = xy - wz;
            m3.m20 = xz + wy;
            
            
            m3.m01 = xy + wz;
            m3.m11 = 1.0 - (xx + zz);
            m3.m21 = yz - wx;
            
            m3.m02 = xz - wy;
            m3.m12 = yz + wx;
            m3.m22 = 1.0 - (xx + yy);
        }
        return m3;
    }
    
    static __inline__ GLVector4 GLMatrix3ToQuat(GLMatrix3 m) {
        GLfloat s;
        GLVector4 tq,q;
        int    i, j;
        
        tq.x = 1 + m.m00+m.m11+m.m22;
        tq.y = 1 + m.m00-m.m11-m.m22;
        tq.z = 1 - m.m00+m.m11-m.m22;
        tq.w = 1 - m.m00-m.m11+m.m22;
        
        j = 0;
        for(i=1;i<4;i++) j = (tq.v[i]>tq.v[j])? i : j;
        
        if (j==0)
        {
            q.w = tq.v[0];
            q.x = m.m12-m.m21;
            q.y = m.m20-m.m02;
            q.z = m.m01-m.m10;
        }
        else if (j==1)
        {
            q.w = m.m12-m.m21;
            q.x = tq.v[1];
            q.y = m.m01+m.m10;
            q.z = m.m20+m.m02;
        }
        else if (j==2)
        {
            q.w = m.m20-m.m02;
            q.x = m.m01+m.m10;
            q.y = tq.v[2];
            q.z = m.m12+m.m21;
        }
        else /* if (j==3) */
        {
            q.w = m.m01-m.m10;
            q.x = m.m20+m.m02;
            q.y = m.m12+m.m21;
            q.z = tq.v[3];
        }
        
        s = sqrt(0.25/tq.v[j]);
        q.w *= s;
        q.x *= s;
        q.y *= s;
        q.z *= s;
        
        return q;
    }
    
    static __inline__ GLMatrix3 GLMatrix3MultiplyAnim(GLMatrix3 MatrixLeft, GLMatrix3 MatrixRight,GLfloat value){
        GLVector4 fv = GLMatrix3ToQuat(MatrixLeft);
        GLVector4 tv = GLMatrix3ToQuat(MatrixRight);
        
        //GLfloat w = fv.w + (tv.w - fv.w) * value;
        
        GLfloat fw =  2.0f * acos(fv.w);
        GLfloat tw =  2.0f * acos(tv.w);
        if(fw > M_PI){
            fw = fw - 2.0f * M_PI;
        }
        if(tw > M_PI){
            tw = tw - 2.0f * M_PI;
        }
        GLfloat w = fw + (tw - fw) * value;
        if(w < 0){
            w = 2.0f * M_PI + w;
        }
        
        w = cos(w / 2 );
        
        
        
        GLVector4 v = {
            fv.x + (tv.x - fv.x) * value,fv.y + (tv.y - fv.y) * value,fv.z + (tv.z - fv.z) * value,w
        };
        return GLquato_Matrix3(v);
    }
    
    static __inline__ GLMatrix4 GLMatrix3ToMatrix4(GLMatrix3 Matrix){
        GLMatrix4 m4 = {
            Matrix.m00,Matrix.m01,Matrix.m02,0.0f,
            Matrix.m10,Matrix.m11,Matrix.m12,0.0f,
            Matrix.m20,Matrix.m21,Matrix.m22,0.0f,
            0.0f,0.0f,0.0f,1.0f
        };
        
        return m4;
    }
    
    static __inline__ GLMatrix4 GLMatrix4MultiplyAnim(GLMatrix4 MatrixLeft, GLMatrix4 MatrixRight,GLfloat value){
        GLMatrix3 m3 = GLMatrix3MultiplyAnim(GLMatrix4ToMatrix3(MatrixLeft),GLMatrix4ToMatrix3(MatrixRight),value);
        GLMatrix4 m4 = GLMatrix3ToMatrix4(m3);
        m4.m30 = MatrixLeft.m30 + (MatrixRight.m30 - MatrixLeft.m30) * value;
        m4.m31 = MatrixLeft.m31 + (MatrixRight.m31 - MatrixLeft.m31) * value;
        m4.m32 = MatrixLeft.m32 + (MatrixRight.m32 - MatrixLeft.m32) * value;
        return m4;
    }
    
    static __inline__ GLVector4 GLquato_axis(GLVector4 q){
        GLVector4 v4;
        GLfloat scale = sqrtf(q.x * q.x + q.y * q.y + q.z * q.z);
        v4.w = 2.0f * acos(q.w);
        if(scale ==0.0f){
            v4.x = v4.y = v4.z = 0.0f;
        }
        else{
            v4.x = q.x / scale;
            v4.y = q.y / scale;
            v4.z = q.y / scale;
        }
        return v4;
    }
    
    static __inline__ GLVector4 GLaxiso_quat(GLVector4 a){
        GLVector4 v4;
        v4.w = cos(a.w / 2 );
        v4.x = a.x * sin(a.w / 2);
        v4.y = a.y * sin(a.w / 2);
        v4.z = a.z * sin(a.w / 2 );
        return v4;
    }
    
    static __inline__ GLMatrix3 GLMatrix3MakeProject(GLVector3 v3){
        GLMatrix3 m3 = {
            1 - v3.x * v3.x,- v3.x * v3.y,- v3.x * v3.z,
            - v3.x * v3.y,1 - v3.y * v3.y, - v3.y * v3.z,
            - v3.x * v3.z,- v3.y * v3.z,1 - v3.z * v3.z
        };
        return m3;
    }
    
    static __inline__ GLMatrix4 GLMatrix4MakeProject(GLVector3 v3){
        GLMatrix4 m4 = {
            1 - v3.x * v3.x,- v3.x * v3.y,- v3.x * v3.z,0.0f,
            - v3.x * v3.y,1 - v3.y * v3.y, - v3.y * v3.z,0.0f,
            - v3.x * v3.z,- v3.y * v3.z,1 - v3.z * v3.z,0.0f,
            0.0f,0.0f,0.0f,1.0f
        };
        return m4;
    }
    
}

#endif /* defined(__glelement__GL__) */
