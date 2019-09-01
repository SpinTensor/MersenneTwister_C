#ifndef MT_RANDOM_H
#define MT_RANDOM_H
   ////////////////////////////////////////////////////////////////////////////////
   // Description:
   //    Contains routines to use a non global mersenne twister for int,
   //    uniformly, and gaussian distributed pseudo random number generation. 
   //    The random number states are independen of each other, which allows for 
   //    arbritrarily many independend streams.
   // Usage:
   //    Import this header:
   //       #import "random.h"
   //    Define a variable to hold the RNG state for uniform random numbers:
   //       rng_uniform_type rng_stateu
   //    For gaussian random numbers:
   //       rng_gaussian_type rng_stateg
   //    For int and long int random numbers over the complete int/long int range
   //       rng_integer_type :: rng_statei
   //    Initialize the uniform random nuber state:
   //       rng_stateu = init_rng(seed, lowerbound, upperbound)
   //    Initialize the gaussian random nuber state:
   //       rng_stateg = init_rng_gaussian(seed, meanvalue, stddev)
   //    Initialize the int/long int random number state:
   //       rng_statei = init_rng_int(seed)
   //    Get the next random number:
   //       Uniform:
   //          random_number = next_random_uniform(&rng_rng_stateu) ;
   //       Gaussian:
   //          random_number = next_random_gaussian(&rng_rng_stateg) ;
   //       Int:
   //          random_number = next_random_int(&rng_rng_statei) ;
   //       Long int:
   //          random_number = next_random_lint(&rng_rng_statei) ;
   //    Store the state in a string for writeout:
   //       Uniform:
   //          state_string = get_random_state_uniform(rng_stateu)
   //       Gaussian:
   //          state_string = get_random_state_gaussian(rng_stateg)
   //       Int / Lint:
   //          state_string = get_random_state_int(rng_statei)
   //    Restore a previously extracted state:
   //       Uniform:
   //          rng_stateu = get_random_state_uniform(state_string)
   //       Gaussian:
   //          rng_stateg = get_random_state_gaussian(state_string)
   //       Int / Lint:
   //          rng_statei = get_random_state_int(state_string)
   //    There is no need for freeing anything except the state string pointer
   ////////////////////////////////////////////////////////////////////////////////

   #include <stdbool.h>

   #define MTSTATESIZE 312

   /////////////////////////////////////////////////////////////////////////////
   // Description:
   //    Type to hold the state of an int random number generator
   // Variables:
   //    seed: The seed
   //    mtstate: State of the mersenne twister
   //    mtidx: index of the current random number of current state
   /////////////////////////////////////////////////////////////////////////////
   typedef struct rng_int_s {
      int seed ;
      int mtidx ;
      long int mtstate[MTSTATESIZE] ;
   } rng_int_type ;

   /////////////////////////////////////////////////////////////////////////////
   // Description:
   //    Type to hold the state of uniform random number generator
   // Variables:
   //    seed: The seed
   //    lower: lower bound of random numbers
   //    upper: upper bound of random numbers
   //    mtstate: State of the mersenne twister
   //    mtidx: index of the current random number of current state
   /////////////////////////////////////////////////////////////////////////////
   typedef struct rng_uniform_s {
      double lower ;
      double upper ;
      rng_int_type rng_int;
   } rng_uniform_type ;

   /////////////////////////////////////////////////////////////////////////////
   // Description:
   //    Type to hold the state of gaussian random number generator
   // Variables:
   //    mean: mean value of the gaussian
   //    stddev: standard deviation of the gaussian
   //    z1: first random number of Box-Muller algorithm
   //    z2: second random number of Box-Muller algorithm
   //    generated: Boolean if Box-Muller needs to be reexecuted
   //    rng_uniform: uniform random number state
   /////////////////////////////////////////////////////////////////////////////
   typedef struct rng_gaussian_s {
      double mean ; 
      double stddev ;
      double z1, z2 ;
      bool generated ; 
      rng_uniform_type rng_uniform ;
   } rng_gaussian_type;

   /////////////////////////////////////////////////////////////////////////////
   // Description:
   //    Initializes a int random number generator
   // Variables:
   //    seed: The seed
   // Return value:
   //    rng_int: int random number state
   /////////////////////////////////////////////////////////////////////////////
   rng_int_type init_rng_int(int seed);

   /////////////////////////////////////////////////////////////////////////////
   // Description:
   //    Initializes a uniform random number generator
   // Variables:
   //    seed: The seed
   //    lower: lower bound of random numbers
   //    upper: upper bound of random numbers
   // Return value:
   //    rng_uniform: uniform random number state
   /////////////////////////////////////////////////////////////////////////////
   rng_uniform_type init_rng_uniform(int seed, double lower, double upper);

   /////////////////////////////////////////////////////////////////////////////
   // Description:
   //    Initializes a gaussian random number generator
   // Variables:
   //    seed: The seed
   //    mean: Mean value of the gaussian
   //    stddev: standard deviation of the gaussian
   // Return value:
   //    rng_gaussian: gaussian random number state
   /////////////////////////////////////////////////////////////////////////////
   rng_gaussian_type init_rng_gaussian(int seed, double mean, double stddev);


   /////////////////////////////////////////////////////////////////////////////
   // Description:
   //    Generates the next int random number
   // Variables:
   //    rng_int: Random number generator state
   // Return value:
   //    randnum: next random number
   /////////////////////////////////////////////////////////////////////////////
   int next_random_int(rng_int_type* rng_int);
   
   /////////////////////////////////////////////////////////////////////////////
   // Description:
   //    Generates the next int random number
   // Variables:
   //    rng_int: Random number generator state
   // Return value:
   //    randnum: next random number
   /////////////////////////////////////////////////////////////////////////////
   long next_random_lint(rng_int_type* rng_int);
   
   /////////////////////////////////////////////////////////////////////////////
   // Description:
   //    Generates the next int random number
   // Variables:
   //    rng_uniform: Random number generator state
   // Return value:
   //    randnum: next random number
   /////////////////////////////////////////////////////////////////////////////
   double next_random_uniform(rng_uniform_type* rng_uniform);
   
   /////////////////////////////////////////////////////////////////////////////
   // Description:
   //    Generates the next int random number
   // Variables:
   //    rng_gaussian: Random number generator state
   // Return value:
   //    randnum: next random number
   /////////////////////////////////////////////////////////////////////////////
   double next_random_gaussian(rng_gaussian_type* rng_gaussian);


   /////////////////////////////////////////////////////////////////////////////
   // Description:
   //    Save rng state to a string
   // Variables:
   //    rng_int: Random number generator state
   // Return value:
   //    intstate: that contains all the state information
   /////////////////////////////////////////////////////////////////////////////
   char* get_random_state_int(rng_int_type* rng_int);
   
   /////////////////////////////////////////////////////////////////////////////
   // Description:
   //    Save rng state to a string
   // Variables:
   //    rng_uniform: Random number generator state
   // Return value:
   //    uniformstate: that contains all the state information
   /////////////////////////////////////////////////////////////////////////////
   char* get_random_state_uniform(rng_uniform_type* rng_uniform);
   
   /////////////////////////////////////////////////////////////////////////////
   // Description:
   //    Save rng state to a string
   // Variables:
   //    rng_gaussian: Random number generator state
   // Return value:
   //    gaussianstate: that contains all the state information
   /////////////////////////////////////////////////////////////////////////////
   char* get_random_state_gaussian(rng_gaussian_type* rng_gaussian);
   
   
   /////////////////////////////////////////////////////////////////////////////
   // Description:
   //    Restore rng state from a string
   // Variables:
   //    intstate: that contains all the state information
   // Return value:
   //    rng_int: Random number generator state
   /////////////////////////////////////////////////////////////////////////////
   rng_int_type restore_rng_state_int(char* rng_state);
   
   /////////////////////////////////////////////////////////////////////////////
   // Description:
   //    Restore rng state from a string
   // Variables:
   //    uniformstate: that contains all the state information
   // Return value:
   //    rng_uniform: Random number generator state
   /////////////////////////////////////////////////////////////////////////////
   rng_uniform_type restore_rng_state_uniform(char* rng_state);
   
   /////////////////////////////////////////////////////////////////////////////
   // Description:
   //    Restore rng state from a string
   // Variables:
   //    gaussianstate: that contains all the state information
   // Return value:
   //    rng_gaussian: Random number generator state
   /////////////////////////////////////////////////////////////////////////////
   rng_gaussian_type restore_rng_state_gaussian(char* rng_state);

#endif
