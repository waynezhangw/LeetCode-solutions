<?php

class Solution {

    /**
     * @param String $address
     * @return String
     */
    function defangIPaddr($address) {
        $divide = explode(".", $address);
        $merge = implode("[.]", $divide);
        return $merge;
    }
}