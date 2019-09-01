# MersenneTwister_C

Description:
   Contains routines to use a non global mersenne twister for int,
   uniformly, and gaussian distributed pseudo random number generation. 
   The random number states are independen of each other, which allows for 
   arbritrarily many independend streams.

Compilation:
   Adjust the compiler and flags in the Makefile
   type "make"

Usage:
   Import this header:
      #import "MT_random.h"
   Define a variable to hold the RNG state for uniform random numbers:
      rng_uniform_type rng_stateu
   For gaussian random numbers:
      rng_gaussian_type rng_stateg
   For int and long int random numbers over the complete int/long int range
      rng_integer_type :: rng_statei
   Initialize the uniform random nuber state:
      rng_stateu = init_rng(seed, lowerbound, upperbound)
   Initialize the gaussian random nuber state:
      rng_stateg = init_rng_gaussian(seed, meanvalue, stddev)
   Initialize the int/long int random number state:
      rng_statei = init_rng_int(seed)
   Get the next random number:
      Uniform:
         random_number = next_random_uniform(&rng_rng_stateu) ;
      Gaussian:
         random_number = next_random_gaussian(&rng_rng_stateg) ;
      Int:
         random_number = next_random_int(&rng_rng_statei) ;
      Long int:
         random_number = next_random_lint(&rng_rng_statei) ;
   Store the state in a string for writeout:
      Uniform:
         state_string = get_random_state_uniform(rng_stateu)
      Gaussian:
         state_string = get_random_state_gaussian(rng_stateg)
      Int / Lint:
         state_string = get_random_state_int(rng_statei)
   Restore a previously extracted state:
      Uniform:
         rng_stateu = get_random_state_uniform(state_string)
      Gaussian:
         rng_stateg = get_random_state_gaussian(state_string)
      Int / Lint:
         rng_statei = get_random_state_int(state_string)
   There is no need for freeing anything except the state string pointer
