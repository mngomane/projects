<?php

namespace App\Service\Snail;

class Shifting
{
    public function getIndex(int $position, int $dimension): int
    {
        if (1 === $position) {
            return 0;
        }

        if (0 <= $position && $position <= $dimension) {
            // Move down
            return $this->getIndex($position - 1, $dimension) + 1;
        }

        if ($dimension <= $position && $position <= 2 * $dimension) {
            // Move left
            return $this->getIndex($position - 1, $dimension) + $dimension;
        }

        if (2 * $dimension < $position && $position < 3 * $dimension) {
             // Move up
            return $this->getIndex($position - 1, $dimension) - 1;
        }

        // Move Right
        return $this->getIndex($position - 1, $dimension) - $dimension;
    }
}
