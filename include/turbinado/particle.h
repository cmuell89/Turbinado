#ifndef PARTICLE_H_INCLUDED
#define PARTICLE_H_INCLUDED

namespace turbinado {

    /**
    A particle is the simplest object that can be sumulated in the physics system.
    */

    class Particle
    {

    protected:

        /** Holds the linear position of the particle in world space */
        Vector3D position;

        /** Holds the linear velocity of the particle in world space */
        Vector3D velocity;

        /**
        * Holds the amount of damping applied to linear motion. Damping is required to remove
        * enery through muerical instability in the integrator. This value and also be used to
        * implement simple drag forces, such as basic air resistance.
        */
        real damping:

        /**
        * Holds the inverse of the mass of the particle. It is more useful
        * to hold the inverse mass because integration is simpler and because
        * in real-time simulation it is more useful to have objects with infinite mass
        * (immovable) than zero mass (complete unstable in numerical simulation)
        */
        real inverseMass;

        /**
        * Holds the accumulated force to be applied at the next sumulation iteration only.
        * This value is zeroed at each integration step.
        */

        Vector3D forceAccum;

        /**
        * Holds the acceleration of a particle. THis value can be used to set acceleration
        * due to gravity (primary use) or any other constant acceleration.
        */
        Vector3D acceleration;



    public:

        /**
        * Integrates the particle forward in time by the given amount.
        * This function uses a Newton-Euler integration method, which is a
        * linear approximation of the correct integral. For this reason it
        * may be inaccurate in some cases.
        */

        void integrate(real duration);

        /**
         * Sets the mass of the particle.
         *
         * @param mass The new mass of the body. This may not be zero.
         * Small masses can produce unstable rigid bodies under
         * simulation.
         *
         * @warning This invalidates internal data for the particle.
         * Either an integration function, or the calculateInternals
         * function should be called before trying to get any settings
         * from the particle.
         */

        void setMass(const real mass);

          /**
         * Gets the mass of the particle.
         *
         * @return The current mass of the particle.
         */

        real getMass() const;

          /**
         * Sets the inverse mass of the particle.
         *
         * @param inverseMass The new inverse mass of the body. This
         * may be zero, for a body with infinite mass
         * (i.e. unmovable).
         *
         * @warning This invalidates internal data for the particle.
         * Either an integration function, or the calculateInternals
         * function should be called before trying to get any settings
         * from the particle.
         */

         void setInverseMass(const real inverseMass);

         /**
         * Gets the inverse mass of the particle.
         *
         * @return The current inverse mass of the particle.
         */

         real getInverseMass() const;

         /**
         * Returns true if the mass of the particle is not-infinite.
         */

         bool hasFiniteMass() const;

          /**
         * Sets both the damping of the particle.
         */

         void setDamping(const real damping);

         /**
         * Sets the position of the particle.
         *
         * @param position The new position of the particle.
         */

         void setPosition(const Vector3D &position);

         /**
         * Sets the position of the particle by component.
         *
         * @param x The x coordinate of the new position of the rigid
         * body.
         *
         * @param y The y coordinate of the new position of the rigid
         * body.
         *
         * @param z The z coordinate of the new position of the rigid
         * body.
         */

         void setPosition(const real x, const real y, const real z);

         /**
         * Fills the given vector with the position of the particle.
         *
         * @param position A pointer to a vector into which to write
         * the position.
         */

         void getPosition(Vector3D *position) const;

         /**
         * Sets the velocity of the particle.
         *
         * @param velocity The new velocity of the particle.
         */

         void setVelocity(const Vector3D &velocity);

         /**
         * Sets the velocity of the particle by component.
         *
         * @param x The x coordinate of the new velocity of the rigid
         * body.
         *
         * @param y The y coordinate of the new velocity of the rigid
         * body.
         *
         * @param z The z coordinate of the new velocity of the rigid
         * body.
         */

         void setVelocity(const real x, const real y, const real z);

         /**
         * Fills the given vector with the velocity of the particle.
         *
         * @param velocity A pointer to a vector into which to write
         * the velocity. The velocity is given in world local space.
         */

         void getVelocity(Vector3D *velocity) const;

         /**
         * Gets the velocity of the particle.
         *
         * @return The velocity of the particle. The velocity is
         * given in world local space.
         */

         Vector3D getVelocity() const;

         /**
         * Sets the constant acceleration of the particle.
         *
         * @param acceleration The new acceleration of the particle.
         */

         void setAcceleration(const Vecotr3D &acceleration);

         /**
         * Sets the constant acceleration of the particle by component.
         *
         * @param x The x coordinate of the new acceleration of the rigid
         * body.
         *
         * @param y The y coordinate of the new acceleration of the rigid
         * body.
         *
         * @param z The z coordinate of the new acceleration of the rigid
         * body.
         */

         void seAcceleration(const real x, const real y, const real z);

         /**
         * Fills the given vector with the acceleration of the particle.
         *
         * @param acceleration A pointer to a vector into which to write
         * the acceleration. The acceleration is given in world local space.
         */

         void getAcceleration(Vector3D *acceleration) const;

         /**
         * Gets the acceleration of the particle.
         *
         * @return The acceleration of the particle. The acceleration is
         * given in world local space.
         */

         Vector3D getAcceleration() const;

         /*@}*/

        /**
         * @name Force Set-up Functions
         *
         * These functions set up forces to apply to the
         * particle.
         */
        /*@{*/

        /**
         * Clears the forces applied to the particle. This will be
         * called automatically after each integration step.
         */

         void clearAccumulator();

         /**
         * Adds the given force to the particle, to be applied at the
         * next iteration only.
         *
         * @param force The force to apply.
         */

         void addForce(const Vector3D &force);

    };
}
#endif // PARTICLE_H_INCLUDED
