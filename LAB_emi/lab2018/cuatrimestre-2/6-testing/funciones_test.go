package funciones

import (
	"testing"
	"github.com/stretchr/testify/assert"
)

func TestDivisionOK(t *testing.T) {

	result, err := Division(6, 2)

	assert.Nil(t, err)
	assert.EqualValues(t, 3, result)
}

func TestDivisionFail(t *testing.T) {

	_, err := Division(6, 0)

	assert.NotNil(t, err)
}