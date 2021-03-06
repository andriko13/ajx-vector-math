#ifndef AJX_VEC3D
#define AJX_VEC3D

#include <boost/operators.hpp>
#include "constants.h"
#include <cmath>

namespace ajx {

    template <class T>
    class vec3d : boost::operators< vec3d<T> > {
        public:

        	vec3d() {
        		this->m_x = 0;
        		this->m_y = 0;
        		this->m_z = 0;
        	};

            vec3d(T t1, T t2, T t3) {
				this->m_x = t1;
				this->m_y = t2;
				this->m_z = t3;
   			};

   			vec3d(const vec3d<T> &myvec) {
   				this->m_x = myvec.m_x;
   				this->m_y = myvec.m_y;
   				this->m_z = myvec.m_z;
   			}

            ~vec3d() {

            };

            static vec3d<T> ZeroVector() {
            	vec3d<T> myvec;
				myvec.m_x = 0;
				myvec.m_y = 0;
				myvec.m_z = 0;
				return myvec;
		    }

		    static vec3d<T> VectorWith(const T &x, const T &y, const T &z) {
		    	vec3d<T> myvec(x,y,z);
		    	return myvec;
		    }


            bool operator<(const vec3d<T>& x) const {
            	return ((this->lengthSquared()) < (x.lengthSquared()));
            };

		    bool operator==(const vec3d<T>& x) const {
		    	if (this->m_x != x.m_x) return false;
		    	if (this->m_y != x.m_y) return false;
		    	if (this->m_z != x.m_z) return false;
		    	return true;
		    };

		    vec3d<T>& operator+=(const vec3d<T>& x) {
		    	this->m_x += x.m_x;
		    	this->m_y += x.m_y;
		    	this->m_z += x.m_z;
		    	return *this;
		    };

		    vec3d<T>& operator-=(const vec3d<T>& x) {
		    	this->m_x -= x.m_x;
		    	this->m_y -= x.m_y;
		    	this->m_z -= x.m_z;
		    	return *this;
		    };

		    vec3d<T>& operator*=(const vec3d<T>& x) {
				this->m_x = this->m_x * x.m_x;
				this->m_y = this->m_y * x.m_y;
				this->m_z = this->m_z * x.m_z;
				return *this;
			};

		    vec3d<T>& operator/=(const vec3d<T>& x) {
		    	this->m_x /= x.m_x;
		    	this->m_y /= x.m_y;
		    	this->m_z /= x.m_z;
		    	return *this;
		    };

		    vec3d<T>& operator%=(const vec3d<T>& x) {
		    	this->m_x %= x.m_x;
		    	this->m_y %= x.m_y;
		    	this->m_z %= x.m_z;
		    	return *this;
		    };

		    vec3d<T>& operator|=(const vec3d<T>& x) {
		    	this->m_x |= x.m_x;
		    	this->m_y |= x.m_y;
		    	this->m_z |= x.m_z;
		    	return *this;
		    };

		    vec3d<T>& operator&=(const vec3d<T>& x) {
		    	this->m_x &= x.m_x;
		    	this->m_y &= x.m_y;
		    	this->m_z &= x.m_z;
		    	return *this;
		    };

		    vec3d<T>& operator^=(const vec3d<T>& x) {
		    	this->m_x ^= x.m_x;
		    	this->m_y ^= x.m_y;
		    	this->m_z ^= x.m_z;
		    	return *this;
		    };

		    vec3d<T>& operator++() {
		    	this->m_x += 1;
		    	this->m_y += 1;
		    	this->m_z += 1;
		    	return *this;
		    };

		    vec3d<T>& operator--() {
		    	this->m_x -= 1;
		    	this->m_y -= 1;
		    	this->m_z -= 1;
		    	return *this;
		    };

		    vec3d<T> operator *(const T& val) const {
		    	vec3d<T> result(this->m_x * val, this->m_y * val, this->m_z * val);
		    	return result;
		    }

		    friend vec3d<T> operator * (const T& val, const vec3d<T>& V) {
		    	vec3d<T> myvec;
		    	myvec.m_x = V.m_x * val;
		    	myvec.m_y = V.m_y * val;
		    	myvec.m_z = V.m_z * val;
		    	return myvec;
		    }

		    vec3d<T>& operator/=(const T& val) {
		    	this->m_x /= val;
		    	this->m_y /= val;
		    	this->m_z /= val;
		    	return *this;
		    };

		    vec3d<T> operator / (const T& val) const {
		    	vec3d<T> result(this->m_x / val, this->m_y / val, this->m_z / val);
		    	return result;
		    }

		    bool equals(const vec3d<T>& x) const {
		    	T resultx = x.m_x - this->m_x;
		    	T resulty = x.m_y - this->m_y;
		    	T resultz = x.m_z - this->m_z;
		    	resultx = (resultx < 0) ? -1 * resultx : resultx;
		    	resulty = (resulty < 0) ? -1 * resulty : resulty;
		    	resultz = (resultz < 0) ? -1 * resultz : resultz;
		    	if (resultx < epsilon && resulty < epsilon && resultz < epsilon) return true;
		    	return false;
		    };

            T x() { return m_x; };
            T y() { return m_y; };
            T z() { return m_z; };
            T dot(const vec3d<T> &U) const { return (m_x * U.m_x + m_y * U.m_y + m_z * U.m_z); };
            //cross will return another vector
            vec3d<T> cross(const vec3d<T> &U) const {
            	vec3d<T> result(m_y*U.m_z - m_z*U.m_y, m_z*U.m_x - m_x*U.m_z, m_x*U.m_y - m_y*U.m_x);
            	return result;
            };
            T length() const { return std::sqrt(m_x*m_x + m_y*m_y + m_z*m_z); };
            T lengthSquared() const { return (m_x*m_x + m_y*m_y + m_z*m_z); };

            vec3d<T> normalized() const {
            	vec3d<T> myvec(this->m_x, this->m_y, this->m_z);
            	T veclength = this->length();
            	if (veclength < epsilon) return myvec;
            	myvec /= veclength;
            	return myvec;
            };

            vec3d<T> rotateAboutAxis(const double &angle, const vec3d<T> &N)
            {
            	vec3d<T> normal = N;
            	normal = normal.normalized();
            	vec3d<T> R(this->m_x, this->m_y, this->m_z);
            	vec3d<T> newVec = (R * (cos(angle)) + ((normal.cross(R)) * (sin(angle))));
            	return newVec;
            }

            vec3d<T> absoluteValue()
            {
            	vec3d<T> myvec(this->m_x, this->m_y, this->m_z);
            	if(this->m_x < 0)
            		myvec.m_x *= -1;
            	if(this->m_y < 0)
            		myvec.m_y *= -1;
            	if(this->m_z < 0)
            		myvec.m_z *= -1;
            	return myvec;
            }

            T magnitude()
            {
            	return std::sqrt((this->m_x *= this->m_x) + (this->m_y *= this->m_y) + (this->m_z *= this->m_z));
            }

            T angleBetween(const vec3d<T> &Vec)
            {
            	vec3d<T> myvec(this->m_x, this->m_y, this->m_z);
            	vec3d<T> a = myvec; vec3d<T> b = Vec;
            	double numerator = a.dot(b);
            	a = myvec; b = Vec;
            	T d_1 = a.magnitude();
            	T d_2 = b.magnitude();
            	double denominator = d_1 * d_2;
            	T result = numerator / denominator;
            	return acos(result);
            }



        protected:
        	T m_x;
        	T m_y;
        	T m_z;
    };
}

#endif
