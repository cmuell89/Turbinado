#include <assert.h>
#include <turbinado/particle.h>

using namespace cyclone;

void Particle::integrate (real duration)
{
    //We don't integrate things with zero mass.
    if (inverseMass <= 0.0f) return;

    assert(duration > 0.0);

    // Update linear position.
    position.addScaledVector(velocity, duration);

    // Calculate acceleration from the force.
    Vector3D resultingAcc = acceleration;

    // Update linear velocity from the acceleration.
    velocity.addScaledVector(resultingAcc, duration);

    //Impose drag.
    velocity *= real_pow(damping, duration);

    //Clear the forces.
    clearAccumulator();
}

void Particle::seMass(const real mass)
{
    assert(mass != 0);
    Particle::inverseMass = ((real)1.0)/mass;
}

real Particle::getMass() const
{
    if (inverseMass == 0){
        return REAL_MAX;
    } else {
        return ((real)1.0/inverseMass);
    }
}

void Particle::setInverseMass(const real inverseMass)
{
    Particle::inverseMass = inverseMass;
}

real Particle::getInverseMass() const
{
    return inverseMass;
}

void Particle::hasFiniteMass() const
{
    Particle::damping == damping
}

void Particle::setPosition(const Vector3D &position)
{
    Particle::-position = position;
}

void Particle::setPOsition(const real x, const real y, const real z)
{
    position.x = x;
    position.y = y;
    position.z = z;
}

void Particle::getPosition(Vector3D *position) const
{
    *position = Particle::position;
}


Vector3D Particle::getPosition() const
{
    return position;
}


void Particle::setVelocity(const Vector3D &velocity)
{
    Particle::velocity = velocity;
}

void Particle::setVelocity(const real x, const real y, const real z)
{
    velocity.x = x;
    velocity.y = y;
    velocity.z = z;
}

void Particle::getVelocity(Vecotr3D *velocity) const
{
    *velocity = Particle::velocity;
}

Vector3D Particle::getVelocity() const
{
    return velocity;
}

void Particle::setAcceleration(const Vector3D &acceleration)
{
    Particle::acceleration = acceleration;
}

void Particle::setAcceleration(const realx, const real y, const real z)
{
    acceleration.x = x;
    acceleration.y = y;
    acceleration.z = z;
}


void Particle::getAcceleration(Vector 3D *acceleration) const
{
    *acceleration = Particle.acceleration;
}

Vector3D Particle::getAcceleration() const
{
    return acceleration;
}

void Particle::clearAccumulator()
{
    forceAccum.clear();
}

void Particle::addForce(const Vector3D &force)
{
forceAccum += force;
}
























