package io

import (
	"testing"
	"github.com/stretchr/testify/assert"
)

func TestReadFile(t *testing.T) {

	inputs, err := ReadFile("../input.txt")

	assert.Nil(t, err)

	assert.EqualValues(t, 15, len(inputs))
}